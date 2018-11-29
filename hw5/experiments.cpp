#include "client.h"
#include "cache.h"
#include <cstdlib>
#include <iostream>
#include <chrono>
#include <ctime>
#include <vector>
#include <unistd.h>

const std::string ADDRESS = "134.10.127.215:9083";

const Cache::index_type max_memory = 512;
const int key_size = 3; // number of characters in key
const int val_size = 1; // size (bytes) of value
const int count_client_requests = 1024;

// converts an int to a string and pads it,
// ensuring it is at least `length` in length
// used for making all keys the same size
std::string int_to_padded_string(int x) {
    std::string s = std::to_string(x);
    while (s.length() < key_size) { s = s + "_"; }
    return s;
}

enum class Action { Set, Get, Del };

// generates a set of requests to run an experiment on,
// given the desired distribution of Cache actions
std::vector<std::pair<Action, Cache::key_type>> generate_requests_data(
    int count_so, // set old
    int count_sn, // set new
    int count_g,  // get
    int count_d)  // delete
{
    std::vector<std::pair<Action, Cache::key_type>> actions;
    
    // always make sure there's at least one reference "old" (which is set first)
    // note that |"old"| = 3 so it fits `key_size`
    actions.push_back(std::make_pair<Action, Cache::key_type>(Action::Set, "old"));
    
    // set ols
    for (int i = 0; i < count_so; i++) {
        // "old" is the key that all "set old" actions target
        actions.push_back(std::make_pair<Action, Cache::key_type>(Action::Set, "old"));
    }
    // set new
    for (int i = 0; i < count_sn; i++) {
        // use "i" as the key
        actions.push_back(std::make_pair<Action, Cache::key_type>(Action::Set, int_to_padded_string(i)));
    }
    // get
    for (int i = 0; i < count_g; i++) {
        // always gets "old", which is guaranteed to be set
        actions.push_back(std::make_pair<Action, Cache::key_type>(Action::Get, "old"));
    }
    // delete
    for (int i = 0; i < count_d; i++) {
        // delete corresponding "i". note that there must be less deletes than set news
        actions.push_back(std::make_pair<Action, Cache::key_type>(Action::Del, int_to_padded_string(i)));
    }
    
    return actions;
}

void experiment1() {
    
    // factors to set
    int offer_rate = 1;
    // request distribution
    float dist_so = 0.5; // 1.00
    float dist_sn = 0.25;    // 0.00
    float dist_g  = 0;    // 0.00
    float dist_d  = 0.25;    // 0.00
    
    // generate set of requests data
    auto requests_data = generate_requests_data(
        (int) (dist_so * count_client_requests),
        (int) (dist_sn * count_client_requests),
        (int) (dist_g * count_client_requests),
        (int) (dist_d * count_client_requests));
    
    // start client
    client_address(ADDRESS);
    client_start();
    
    // create new Cache instance, the single one for this experiment
    Cache* cache = new Cache(max_memory);
    
    // start timer
    auto start = std::chrono::steady_clock::now();
    
    // send requests to server, and record timing and such
    // sends all of them as fast as possible, where for each request
    // wait to get a response before sending next request
    Cache::index_type size = 1;
    for (auto it = requests_data.begin(); it != requests_data.end(); ++it) {
        // Send each request to the server
        // The Cache method both sends the request
        // and waits for the response from the server
        // (up to max wait threshold)
        auto data = *it;
        switch (data.first) {
            case Action::Set: cache->set(data.second, "a", 1); break;
            case Action::Get: cache->get(data.second, size); break;
            case Action::Del: cache->del(data.second); break;
        }
    }
    
    // stop timer
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration = end - start;
    
    // report measurements
    auto average_latency_us = duration.count() / count_client_requests;
    std::cout << "average latency per request/response: " << average_latency_us << " us\n";
    
    
    // shutdown server
    // client_request("shutdown", "k", "v");
    
    // stop client
    client_stop();
    
}