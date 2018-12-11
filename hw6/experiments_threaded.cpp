#include <unistd.h>
#include <cstdlib>
#include <assert.h>
#include <stdio.h>
#include <chrono>
#include <thread>
#include <mutex>

#include <atomic>

#include <pistache/net.h>
#include <pistache/http.h>
#include <pistache/client.h>

using namespace Pistache;
using namespace Pistache::Http;

#include "cache.h"

#include "json.h"
using json = nlohmann::json;

const bool DEBUG = true;

Http::Client client;
std::string address = "192.168.84.21:9080"; // TODO: check this works

void client_start() {
    // Http client options
    auto opts = Http::Client::options()
            .threads(1)
            .maxConnectionsPerHost(1);
    client.init(opts);
}

void client_stop() {
    client.shutdown();
}

const Cache::index_type maxmem = 1024;
const int key_size = 8;
const int val_size = 16;
const int requests_count = 1000;

const float request_rate = 10; // requests/second


// converts an int to a string and pads it,
// ensuring it is at least `length` in length
// used for making all keys the same size
std::string int_to_padded_string(int x) {
    std::string s = std::to_string(x);
    while (s.length() < key_size) { s = s + "_"; }
    return s;
}

void run_experiment() {
    
    //
    // GENERATING EXPERIMENT DATA
    //
    const float ratio_set      = 0.3f;
    const float ratio_get_hit  = 0.7f * 0.9f;
    const float ratio_get_miss = 0.7f * 0.1f;
    
    const int index_set      = 0;
    const int index_get_hit  = index_set + ((int) (ratio_set * requests_count));
    const int index_get_miss = index_get_hit + ((int) (ratio_get_hit * requests_count));
    
    const std::chrono::duration<double> request_delay
        = std::chrono::nanoseconds((int) (1000000 / request_rate));
    const std::chrono::duration<double> request_delay_total
        = std::chrono::nanoseconds((int) (requests_count * 1000000 / request_rate));
    std::cout << "request_delay = " << request_delay.count() << "\n";
    
    std::vector<std::string> commands;
    std::vector<std::string> arguments;
    
    int set_counter = 0;
    int get_counter = 0;
    
    // generate commands and arguments
    const std::string get_miss_key = "get_miss"; // 8 bytes
    for (int i = 0; i < requests_count; ++i) {
        // SET
        if (i < index_get_hit) {
            commands.push_back("set");
            arguments.push_back(int_to_padded_string(set_counter));
            set_counter++;
        }
        // GET hit
        else if (i < index_get_miss) {
            commands.push_back("get");
            arguments.push_back(int_to_padded_string(get_counter));
            get_counter++;
        }
        // GET miss
        else {
            commands.push_back("get");
            arguments.push_back(get_miss_key);
        }
    }

    //
    // RUNNING EXPERIMENT
    //
    
    // start client
    client_start();
    
    // start server Cache
    client.post(address + "/new/" + std::to_string(maxmem)).send();
    // track responses
    Http::Cookie cookie = Http::Cookie("Tracker", "tracking tracker");
    std::vector<Async::Promise<Http::Response>> responses;
    
    // start timer
    auto start_time = std::chrono::steady_clock::now();
    
    // send requests, based on commands(arguments)
    std::string resource;
    std::string command;
    std::string argument;
    std::string value = "123456789abcdefg";
    for (int i = 0; i < requests_count; ++i) {
        command  = commands[i];
        argument = arguments[i];
        
        if (command == "get") {
            resource = address + "/key/" + argument;
            auto response = client.get(resource).cookie(cookie).send();
            responses.push_back(std::move(response));
        } else if (command == "set") {
            resource = address + "/key/" + argument + "/" + value;
            auto response = client.put(resource).cookie(cookie).send();
            responses.push_back(std::move(response));
        }
        
        if (DEBUG) { std::cout << resource << "\n"; }
        
        // delay, to throttle request rate
        std::this_thread::sleep_for(request_delay);
    }

    // example on response handler
//    auto response = client.get(resource).cookie(cookie).send();
//    response.then([&](Http::Response response) {
//        response_code = response.code();
//        response_body = response.body(); }, Async::IgnoreException);
//    responses.push_back(std::move(response));
    
    
    // wait for responses
    auto sync = Async::whenAll(responses.begin(), responses.end());
    Async::Barrier<std::vector<Http::Response>> barrier(sync);
    barrier.wait(); // wait until all responses are done    
    
    // end timer
    auto end_time = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration = (end_time - start_time) - request_delay_total;
    
    // stop client
    client_stop();
    // NOTE: don't need to stop server Cache
    
    // calculate results
    auto average_latency = duration.count() / requests_count;
    
    // report results
    std::cout << "average latency; " << average_latency << " seconds\n";
}