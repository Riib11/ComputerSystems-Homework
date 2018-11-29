#include <unistd.h>
#include <getopt.h>

#include <atomic>

#include <pistache/net.h>
#include <pistache/http.h>
#include <pistache/client.h>

using namespace Pistache;
using namespace Pistache::Http;

#include "json.h"
using json = nlohmann::json;

#include "cache.h"

const bool DEBUG = true;

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

Http::Client client;
std::string address;

void client_address(std::string address_) {
    address = address_;
}

void client_start() {
    // Http client options
    auto opts = Http::Client::options()
            .threads(1)
            .maxConnectionsPerHost(8);
    client.init(opts);
}

void client_stop() {
    client.shutdown();
}

std::string client_request(
    std::string command,
    std::string key,
    std::string value
) {
    if (command == "") { error_missing_arg("command"); }
    
    std::string
        cmd_new      = "new",
        cmd_get      = "get",
        cmd_set      = "set",
        cmd_memsize  = "memsize",
        cmd_del      = "del",
        cmd_head     = "head",
        cmd_shutdown = "shutdown";
    
    // create resource
    std::string resource;
    
    // start (memsize)
    if (command == cmd_new) {
        // key serves as memsize
        if (key == "") { error_missing_arg("maxmem"); }
        resource = address + "/new/" + key;
    }
    // get (key)
    else if (command == cmd_get) {
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
    
    if (DEBUG) { std::cout << "resource: " << resource << std::endl; }
    
    // store response
    Http::Cookie cookie = Http::Cookie("Tracker", "tracking");
    std::vector<Async::Promise<Http::Response>> responses;
    std::string response_body = ((json) {{"success", "false"}}).dump();
    auto response_code = Http::Code::Bad_Request;
    
    // GET
    if (command == cmd_get || command == cmd_memsize) {
        auto response = client.get(resource).cookie(cookie).send();
        response.then([&](Http::Response response) {
            response_code = response.code();
            response_body = response.body(); }, Async::IgnoreException);
        responses.push_back(std::move(response));
    }
    // PUT
    else if (command == cmd_set) {
        auto response = client.put(resource).cookie(cookie).send();
        response.then([&](Http::Response response) {
            response_code = response.code();
            response_body = response.body(); }, Async::IgnoreException);
        responses.push_back(std::move(response));
    }
    // DEL
    else if (command == cmd_del) {
        auto response = client.put(resource).cookie(cookie).send();
        response.then([&](Http::Response response) {
            response_code = response.code();
            response_body = response.body(); }, Async::IgnoreException);
        responses.push_back(std::move(response));
    }
    // HEAD
    else if (command == cmd_head) {
        auto response = client.get(resource).cookie(cookie).send();
        response.then([&](Http::Response response) {
            response_code = response.code();
            response_body = response.body(); }, Async::IgnoreException);
        responses.push_back(std::move(response));
    }
    // POST
    else if (command == cmd_new || command == cmd_shutdown) {
        auto response = client.post(resource).cookie(cookie).send();
        response.then([&](Http::Response response) {
            response_code = response.code();
            response_body = response.body(); }, Async::IgnoreException);
        responses.push_back(std::move(response));
    }
    
    // wait for response
    auto sync = Async::whenAll(responses.begin(), responses.end());
    Async::Barrier<std::vector<Http::Response>> barrier(sync);
    barrier.wait_for(std::chrono::seconds(2));
    
    if (DEBUG) { std::cout << "response body: " << response_body << std::endl; }
    
    return response_body;
}