#include "client.h"
#include "cache.h"
#include <cstdlib>
#include <iostream>
#include <chrono>
#include <ctime>
#include <vector>
#include <unistd.h>

const std::string ADDRESS = "192.168.84.21:9084";

const Cache::index_type max_memory = 512;
const int key_size = 3; // number of characters in key
const int val_size = 1; // size (bytes) of value
const int count_client_requests = 1024;
const int scale = 1;

// converts an int to a string and pads it,
// ensuring it is at least `length` in length
// used for making all keys the same size
std::string int_to_padded_string(int x) {
    std::string s = std::to_string(x);
    while (s.length() < key_size) { s = s + "_"; }
    return s;
}

enum class Action { Set, Get, Del };

void to_string(Action a) {
    switch (a) {
        case Action::Set: cout << "set"; break;
        case Action::Get: cout << "get"; break;
        case Action::Del: cout << "del"; break;
    }
}

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

void run_experiment(
    float dist_so,
    float dist_sn,
    float dist_g,
    float dist_d)
{
    // generate set of requests data
    auto requests_data = generate_requests_data(
        (int) (dist_so * count_client_requests * scale),
        (int) (dist_sn * count_client_requests * scale),
        (int) (dist_g  * count_client_requests * scale),
        (int) (dist_d  * count_client_requests * scale));
    
    // start client
    client_address(ADDRESS);
    client_start();
    
    // create new Cache instance, the single one for this experiment
    Cache* cache = new Cache(max_memory + 1);
    
    // start timer
    auto start = std::chrono::steady_clock::now();
    auto now = start;
    auto prev = start;
    std::vector<std::chrono::duration<double>> waal_history;
    
    // send requests to server, and record timing and such
    // sends all of them as fast as possible, where for each request
    // wait to get a response before sending next request
    Cache::index_type size = 1;
    int waal_i = 0;
    int request_i = 0;
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
        
        request_i++;
        waal_i++;
        // update WAAL history
        if (waal_i >= 10) {
            waal_history.push_back((std::chrono::steady_clock::now() - start) / request_i);
            waal_i = 0;
        }
    }
    
    // stop timer
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration = end - start;
    
    
    // average latency
    auto average_latency_us = duration.count()/(count_client_requests * scale);
    std::cout << "average latency per request/response: " << average_latency_us << " us\n";
    
    // sustained throughput
    int max_waal_i = -1;
    for (int i = 0; i < waal_history.size(); ++i) {
        if (waal_history[i] < 0.001) {
            max_waal_i = i;
        } else {
            break;
        }
    }
    float sus_thr = 1.0;
    if (max_waal_i >= 0) {
        sus_thr = max_waal_i * 10 / (count_client_requests * scale);
    }
    std::cout << "sustained throughput: " << sus_thr << "\n";
    
    // shutdown server
    // client_request("shutdown", "k", "v");
    
    // stop client
    client_stop();
}

void experiment1() { run_experiment(
    1.00, // set old    
    0.00, // set new
    0.00, // get
    0.00  // del
); }