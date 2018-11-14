/* http_server.cc
   Mathieu Stefani, 07 février 2016
   Example of an http server
 */

#include "cstdlib"
#include <vector>
#include <pistache/net.h>
#include <pistache/http.h>
#include <pistache/peer.h>
#include <pistache/http_headers.h>
#include <pistache/cookie.h>
#include <pistache/endpoint.h>
#include "cache.h"

using namespace std;
using namespace Pistache;

#include <json.h>
using json = nlohmann::json;

shared_ptr<Http::Endpoint> server;

Cache * cache;

struct PrintException {

    void operator()(exception_ptr exc) const {
        try {
            rethrow_exception(exc);
        } catch (const exception& e) {
            cerr << "An exception occured: " << e.what() << endl;
        }
    }
};

// TODO: header
/*
class CacheHeader : public Http::Header {
public:

    NAME("Cache-Header")

    CacheHeader()
     : data((json) {{}})
    { }

    void parse(const string& s) {
        data = json.parse(s);
    }

    void write(ostream& os) const {
        os << data.dump() << endl;
    }
private:
    json data;
};
*/

struct LoadMonitor {

    LoadMonitor(const shared_ptr<Http::Endpoint>& endpoint)
    : endpoint_(endpoint)
    , interval(chrono::seconds(1)) {
    }

    void setInterval(chrono::seconds secs) {
        interval = secs;
    }

    void start() {
        shutdown_ = false;
        thread.reset(new std::thread(bind(&LoadMonitor::run, this)));
    }

    void shutdown() {
        shutdown_ = true;
    }

    ~LoadMonitor() {
        shutdown_ = true;
        if (thread) thread->join();
    }

private:
    shared_ptr<Http::Endpoint> endpoint_;
    std::unique_ptr<std::thread> thread;
    chrono::seconds interval;

    atomic<bool> shutdown_;

    void run() {
        Tcp::Listener::Load old;
        while (!shutdown_) {
            if (!endpoint_->isBound()) continue;

            endpoint_->requestLoad(old).then([&](const Tcp::Listener::Load & load) {
                old = load;

                double global = load.global;
                if (global > 100) global = 100;

                    if (global > 1)
                            cout << "Global load is " << global << "%" << endl;
                    else
                        cout << "Global load is 0%" << endl;
                    },
            Async::NoExcept);

            this_thread::sleep_for(chrono::seconds(interval));
        }
    }
};

vector<string> split(string str, char splitter) {
    vector<string> seglist;
    string strseg = "";
    stringstream strstream(str);
    while(getline(strstream, strseg, splitter)) {
        seglist.push_back(strseg);
    }
    return seglist;
}

class Handler : public Http::Handler {

    HTTP_PROTOTYPE(Handler);

    void onRequest(
        const Http::Request& req,
        Http::ResponseWriter response) override
    {
        
        using namespace Http;
        
        // parse request
        string res = req.resource();
        auto reslist = split(res, '/');
        auto length = reslist.size() - 1;
        
        // setup response
        json data = {{"success", false}};
        
        // log request
        cout << req.method() << " " << res << endl;
        
        // GET
        if (req.method() == Method::Get) {
            // get (key)
            if (length >= 2 && reslist[1] == "key") {
                // interpret input
                Cache::key_type key = reslist[2];
                Cache::index_type val_size;
                // get key->value from cache
                data["key"] = key;
                
                // cast to string
                const void* val = cache->get(key, val_size);
                const std::string *val_string_ptr = static_cast<const std::string*>(val);
                std::string val_string = *val_string_ptr;
                delete val_string_ptr;
                data["value"] = val_string;
                
                data["success"] = true;
            }
            // memsize
            else if (length >= 1 && reslist[1] == "memsize") {
                // get memused from cache
                data["memused"] = cache->space_used();
                data["success"] = true;
            }
            // head
            else if (length >= 1 && reslist[1] == "head") {
                // HEAD
                data["Version"]         = "1.1";
                // data["Date"]            = to_string(chrono::system_clock::now());
                data["Accept"]          = "text/plain";
                data["Content-Type"]    = "application/json";
                data["success"] = true;
            }
            
            // invalid
            else {
                response.send(Code::Bad_Request, data.dump());
                return;
            }
        }
        
        // PUT
        else if (req.method() == Method::Put) {            
            // set key value
            if (length >= 3 && reslist[1] == "key") {
                // interpret input
                Cache::key_type key = reslist[2];
                // create new cache entry
                
                // cast string to void*
                std::string val_string = reslist[3];
                std::string* val_string_ptr = &val_string;
                Cache::val_type val = val_string_ptr;
                delete val_string_ptr;
                
                Cache::index_type size = reslist[3].size(); // size(char) = 1
                
                // set key->val in cache
                cache->set(key, val, size);
                data["success"] = true;
            }
            // invalid
            else {
                response.send(Code::Bad_Request, data.dump());
                return;
            }
        
        }
        // DELETE
        else if (req.method() == Method::Delete) {
            // delete (key)
            if (length >= 2 && reslist[1] == "key") {
                Cache::key_type key = reslist[2];
                data["success"] = true;
            // invalid
            } else {
                response.send(Code::Bad_Request, data.dump());
                return;
            }
        }
        
        // POST
        else if (req.method() == Method::Post) {
            // shutdown
            if (length >= 1 && reslist[1] == "shutdown") {
                // shutdown server
                server->shutdown();
                data["success"] = true;
            }
            // invalid
            else {
                response.send(Code::Bad_Request, data.dump());
                return;
            }
        }
        // other
        else {
            response.send(Code::Bad_Request, data.dump());
            return;
        }
        
        // respond to successful request from client
        response.send(Code::Ok, data.dump(), MIME(Application, Json));
    }

    void onTimeout(
            const Http::Request& req,
            Http::ResponseWriter response) override {
            UNUSED(req);
            response
                .send(Http::Code::Request_Timeout, "Timeout")
                .then([ = ](ssize_t){}, PrintException());
    }

};

void server_start(int portnum, int maxmem) {
    // register CacheProtocol header
    // TODO: header
    // Http::Header::Registry::registerHeader<CacheHeader>();
    
    // setup server
    Port port(portnum);
    Address addr(Ipv4::any(), port);
    server = make_shared<Http::Endpoint>(addr);
    auto opts = Http::Endpoint::options().threads(1).flags(Tcp::Options::InstallSignalHandler);
    server->init(opts);
        
    // setup cache
    cache = new Cache(maxmem);
    cout << "creating cache with " << maxmem << " space" << endl;
    
    // start server
    server->setHandler(Http::make_handler<Handler>());
    cout << "starting server on port " << portnum << endl;
    server->serve();

    // shutdown server
    cout << "Shutdowning server" << endl;
    server->shutdown();
}

