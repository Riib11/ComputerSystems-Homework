#include <unistd.h>
#include <getopt.h>

#include <atomic>

#include <pistache/net.h>
#include <pistache/http.h>
#include <pistache/client.h>

using namespace Pistache;
using namespace Pistache::Http;

#include <json.h>
using json = nlohmann::json;

void report(Http::Response response) {
    std::cout << "Response code = " << response.code() << std::endl;
    auto body = response.body();
    if (!body.empty()) {
        std::cout << "Response body = " << body << std::endl;
    }
}

void error_missing_arg(std::string args) {
    std::cout << "[!] missing arguments: " << args << std::endl;
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    
    // command words
    std::string
            cmd_get      = "get",
            cmd_memsize  = "memsize",
            cmd_set      = "set",
            cmd_del      = "delete",
            cmd_head     = "head",
            cmd_shutdown = "shutdown";
    
    // parse command line options
    int opt;
    std::string address = "", command = "", key = "", value = "";
    while((opt = getopt(argc, argv, "a:c:k:v:")) != -1) {
        switch(opt) {
            // server address
            case 'a':
                address = optarg;
                break;
            case 'c':
                command = optarg;
                break;
            case 'k':
                key = optarg;
                break;
            case 'v':
                value = optarg;
                break;
            default:
                std::cout << "unrecognized command line argument: " << opt << std::endl;
                exit(EXIT_FAILURE);
        }
    }
    
    // debug command line parse
    std::cout
            << "-----------------------"    << std::endl
            <<  "address: " << address      << std::endl
            <<  "command: " << command      << std::endl
            <<      "key: " << key          << std::endl
            <<    "value: " << value        << std::endl
            << "-------------------------"  << std::endl;
    
    
    if (address == "") { error_missing_arg("address"); }
    if (command == "") { error_missing_arg("command"); }
    
    // declare client
    Http::Client client;

    // Http client options
    auto opts = Http::Client::options()
            .threads(1)
            .maxConnectionsPerHost(8);
    client.init(opts);
    
    // create resource
    std::string resource;
    // get (key)
    if (command == cmd_get) {
        if (key == "") { error_missing_arg("key"); }
        resource = address + "/key/" + key;
    }
    // memsize
    else if (command == cmd_memsize) {
        resource = address + "/memsize";
    }
    // set (key) (value)
    else if (command == cmd_set) {
        if (key == "") { error_missing_arg("key"); }
        if (value == "") { error_missing_arg("value"); }
        resource = address + "/key/" + key + "/" + value;
    }
    // del (key)
    else if (command == cmd_del) {
        if (key == "") { error_missing_arg("key"); }
        resource = address + "/key/" + key;
    }
    // head
    else if (command == cmd_head) {
        resource = address + "/head";
    }
    // shutdown
    else if (command == cmd_shutdown) {
        resource = address + "/shutdown";
    }
    // unrecognized command
    else {
        std::cout << "unrecognized command: " << command << std::endl;
        exit(EXIT_FAILURE);
    }
    
    std::cout << "resource: " << resource << std::endl;
    
    // send request
    Http::Cookie cookie = Http::Cookie("Tracker", "tracking");
    std::vector<Async::Promise<Http::Response>> responses;
    // GET
    if (command == cmd_get || command == cmd_memsize) {
        auto response = client.get(resource).cookie(cookie).send();
        response.then([&](Http::Response response) { report(response); }, Async::IgnoreException);
        responses.push_back(std::move(response));
    }
    // PUT
    else if (command == cmd_set) {
        auto response = client.put(resource).cookie(cookie).send();
        response.then([&](Http::Response response) { report(response); }, Async::IgnoreException);
        responses.push_back(std::move(response));
    }
    // DEL
    else if (command == cmd_del) {
        auto response = client.put(resource).cookie(cookie).send();
        response.then([&](Http::Response response) { report(response); }, Async::IgnoreException);
        responses.push_back(std::move(response));
    }
    // HEAD
    else if (command == cmd_head) {
        auto response = client.get(resource).cookie(cookie).send();
        response.then([&](Http::Response response) { report(response); }, Async::IgnoreException);
        responses.push_back(std::move(response));
    }
    // POST
    else if (command == cmd_shutdown) {
        auto response = client.post(resource).cookie(cookie).send();
        response.then([&](Http::Response response) { report(response); }, Async::IgnoreException);
        responses.push_back(std::move(response));
    }
    
    // wait for response
    auto sync = Async::whenAll(responses.begin(), responses.end());
    Async::Barrier<std::vector<Http::Response>> barrier(sync);
    barrier.wait_for(std::chrono::seconds(5));
    
    // shutdown client
    client.shutdown();
}