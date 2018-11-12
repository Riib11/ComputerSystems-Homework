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

using namespace std;
using namespace Pistache;

#include <json.h>
using json = nlohmann::json;


struct PrintException {

    void operator()(std::exception_ptr exc) const {
        try {
            std::rethrow_exception(exc);
        } catch (const std::exception& e) {
            std::cerr << "An exception occured: " << e.what() << std::endl;
        }
    }
};

struct LoadMonitor {

    LoadMonitor(const std::shared_ptr<Http::Endpoint>& endpoint)
    : endpoint_(endpoint)
    , interval(std::chrono::seconds(1)) {
    }

    void setInterval(std::chrono::seconds secs) {
        interval = secs;
    }

    void start() {
        shutdown_ = false;
        thread.reset(new std::thread(std::bind(&LoadMonitor::run, this)));
    }

    void shutdown() {
        shutdown_ = true;
    }

    ~LoadMonitor() {
        shutdown_ = true;
        if (thread) thread->join();
    }

private:
    std::shared_ptr<Http::Endpoint> endpoint_;
    std::unique_ptr<std::thread> thread;
    std::chrono::seconds interval;

    std::atomic<bool> shutdown_;

    void run() {
        Tcp::Listener::Load old;
        while (!shutdown_) {
            if (!endpoint_->isBound()) continue;

            endpoint_->requestLoad(old).then([&](const Tcp::Listener::Load & load) {
                old = load;

                double global = load.global;
                if (global > 100) global = 100;

                    if (global > 1)
                            std::cout << "Global load is " << global << "%" << std::endl;
                    else
                        std::cout << "Global load is 0%" << std::endl;
                    },
            Async::NoExcept);

            std::this_thread::sleep_for(std::chrono::seconds(interval));
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

    HTTP_PROTOTYPE(Handler)

    void onRequest(
            const Http::Request& req,
            Http::ResponseWriter response) override {
        
        using namespace Http;
        
        string res = req.resource();
        auto reslist = split(res, '/');
        auto length = reslist.size() - 1;

        // GET
        if (req.method() == Method::Get) {
            string msg;
            
            // get key
            if (length >= 2 && reslist[1] == "key") {
                // TODO
                msg += "get key: " + reslist[2];
                response.send(Code::Ok, msg);
            // get memsize
            } else if (length >= 1 && reslist[1] == "memsize") {
                // TODO
                msg += "get memsize";
                response.send(Code::Ok, msg);
            // invalid
            } else {
                // TODO
                msg += "invalid GET";
                response.send(Code::Bad_Request, msg);
            }
        }
        // PUT
        else if (req.method() == Method::Put) {
            string msg;
            
            // set key value
            if (length >= 3 && reslist[1] == "key") {
                // TODO
                msg += "set key to value: " + reslist[2] + " = " + reslist[3];
                response.send(Code::Ok, msg);
            // invalid
            } else {
                // TODO
                msg += "invalid PUT";
                response.send(Code::Bad_Request, msg);
            }
        
        }
        // DELETE
        else if (req.method() == Method::Delete) {
            string msg;
            
            // delete key
            if (length >= 2 && reslist[1] == "key") {
                // TODO
                msg += "delete key: " + reslist[2];
                response.send(Code::Ok, msg);
            // invalid
            } else {
                msg += "invalid DELETE";
                response.send(Code::Bad_Request, msg);
            }
        }
        // HEAD
        else if (req.method() == Method::Head) {
            string msg;
            // header of key
            if (length >= 2 && reslist[1] == "key") {
                // TODO
                msg += "header for key: " + reslist[2];
                response.send(Code::Ok, msg);
            // invalid
            } else {
                msg += "invalid HEAD";
                response.send(Code::Bad_Request, msg);
            }
        }
        // POST
        else if (req.method() == Method::Post) {
            string msg;
            // shutdown
            if (length >= 1 && reslist[1] == "shutdown") {
                // TODO
                msg += "clean up and shut down";
                response.send(Code::Ok, msg);
            } else {
                // TODO
                msg += "invalid POST";
                response.send(Code::Bad_Request, msg);
            }
        }
        // other
        else {
            string msg;
            msg += "unsupported HTTP command";
            response.send(Code::Bad_Request, msg);
        }
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

int main(int argc, char *argv[]) {
    Port port(9080);

    int thr = 2;

    if (argc >= 2) {
        port = std::stol(argv[1]);

        if (argc == 3)
            thr = std::stol(argv[2]);
    }

    Address addr(Ipv4::any(), port);

    cout << "Cores = " << hardware_concurrency() << endl;
    cout << "Using " << thr << " threads" << endl;

    auto server = std::make_shared<Http::Endpoint>(addr);

    auto opts = Http::Endpoint::options()
            .threads(thr)
            .flags(Tcp::Options::InstallSignalHandler);
    server->init(opts);
    server->setHandler(Http::make_handler<Handler>());
    server->serve();

    std::cout << "Shutdowning server" << std::endl;
    server->shutdown();
}