#include "client.h"
#include "cache.h"
#include <cstdlib>
#include <iostream>
#include <chrono>
#include <ctime>
#include <vector>
#include <unistd.h>
#include <algorithm>

const std::string ADDRESS = "192.168.84.21:9082";

//const int scale = 1;
//const int scale = 8;
const int scale = 16;
const Cache::index_type max_memory = (512 * scale * 2);
const int key_size = 4; // number of characters in key
const int val_size = 1; // size (bytes) of value
const int count_client_requests = (1024 * scale) + 1;

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
    
    // always make sure there's at least one reference "old_" (which is set first)
    // note that |"old_"| = 3 so it fits `key_size`
    actions.push_back(std::make_pair<Action, Cache::key_type>(Action::Set, "old_"));
    
    // set old
    for (int i = 0; i < count_so; i++) {
        // "old_" is the key that all "set old" actions target
        actions.push_back(std::make_pair<Action, Cache::key_type>(Action::Set, "old_"));
    }
    // set new
    for (int i = 0; i < count_sn; i++) {
        // use "i" as the key
        actions.push_back(std::make_pair<Action, Cache::key_type>(Action::Set, int_to_padded_string(i)));
    }
    // get
    for (int i = 0; i < count_g; i++) {
        // always gets "old_", which is guaranteed to be set
        actions.push_back(std::make_pair<Action, Cache::key_type>(Action::Get, "old_"));
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
        (int) (dist_so * count_client_requests),
        (int) (dist_sn * count_client_requests),
        (int) (dist_g  * count_client_requests),
        (int) (dist_d  * count_client_requests));
    
    // start client
    client_address(ADDRESS);
    client_start();
    
    // create new Cache instance, the single one for this experiment
    Cache* cache = new Cache(max_memory);
    
    // start timer
    auto start = std::chrono::steady_clock::now();
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
    // last update for WAAL history
    waal_history.push_back((std::chrono::steady_clock::now() - start) / request_i);
    
    // stop timer
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration = end - start;
    
    
    // average latency
    auto average_latency_us = duration.count()/(count_client_requests);
    std::cout << average_latency_us << " s | ";
    
    // sustained throughput
    int max_waal_i = -1;
    for (int i = 0; i < waal_history.size(); ++i) {
        if (waal_history[i].count() <= 0.001) {
            max_waal_i = i;
        } else {
            break;
        }
    }
    float sus_thr = -1.0f;
    if (max_waal_i < count_client_requests) {
        sus_thr = max_waal_i * 10.0f / (count_client_requests);
    }
    sus_thr = std::min(1.0f, sus_thr); // max of 1.0
    std::cout << sus_thr << " |\n";
    
    // shutdown server
//     client_request("shutdown", "k", "v");
    
    // stop client
    client_stop();
}

void experiment1() { run_experiment(
    1.00, // set old    
    0.00, // set new
    0.00, // get
    0.00  // del
); }

void experiment2() { run_experiment(
    0.00, // set old    
    1.00, // set new
    0.00, // get
    0.00  // del
); }


void experiment3() { run_experiment(
    0.00, // set old    
    0.50, // set new
    0.50, // get
    0.00  // del
); }


void experiment4() { run_experiment(
    0.00, // set old    
    0.50, // set new
    0.00, // get
    0.50  // del
); }


void experiment5() { run_experiment(
    0.00, // set old    
    0.50, // set new
    0.25, // get
    0.25  // del
); }