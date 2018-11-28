#include "client.h"
#include "cache.h"
#include <cstdlib>
#include <iostream>
#include <chrono>
#include <ctime>
#include <vector>
#include <unistd.h>

const std::string ADDRESS = "192.168.84.23:9082";

const Cache::index_type max_memory = 256;
const int key_size = 2;
const int val_size = 3; // number of characters in a value
const int count_client_requests = 128;

// converts an int to a string and pads it,
// ensuring it is at least `length` in length
std::string int_to_padded_string(int x) {
    std::string s = std::tostring(x);
    while (s.length() < val_size) { s = s + "_"; }
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
    // note that |"old"| = 3 so it fits `val_size`
    actions.push_back(std::make_pair<Action, Cache::key_type>(Set, "old"));
    
    // set ols
    for (int i = 0; i < count_so; i++) {
        // "old" is the key that all "set old" actions target
        actions.push_back(std::make_pair<Action, Cache::key_type>(Set, "old"));
    }
    // set new
    for (int i = 0; i < count_sn; i++) {
        // use "i" as the key
        actions.push_back(std::make_pair<Action, Cache::key_type>(Set, int_to_padded_string(i)));
    }
    // get
    for (int i = 0; i < count_g; i++) {
        // always gets "old", which is guaranteed to be set
        actions.push_back(std::make_pair<Action, Cache::key_type>(Get, "old"));
    }
    // delete
    for (int i = 0; i < count_d; i++) {
        // delete corresponding "i". note that there must be less deletes than set news
        actions.push_back(std::make_pair<Action, Cache::key_type>(Del, int_to_padded_string(i)));
    }
    
    return actions;
}

void experiment1() {
    
    int offer_rate = 1;
    int count_so = 128; // 1.00
    int count_sn = 0;   // 0.00
    int count_g  = 0;   // 0.00
    int count_d  = 0;   // 0.00
    
    // calculate sleep time (in microseconds)
    unsigned long delay_us = (1000000 / offer_rate);
    
    // generate set of requests data
    auto requests_data = generate_requests_data(count_so, count_sn, count_g, count_d); 

    // start client
    client_address(ADDRESS);
    client_start();
    
    // create new Cache instance, the single one for this experiment
    Cache* cache = new Cache(256);
    
    // start timer
    auto start = std::chrono::steady_clock::now();
    
    // send requests to server, and record timing and such
    for (auto it = requests_data.begin(); it != requests_data.end(); ++it) {
        auto data = requests_data[it];
        switch (data.first) {
            case Set: cache->set(data.second); break;
            case Get: cache->get(data.second); break;
            case Del: cache->del(data.second); break;
        }
        // sleep for enough time to yield the correct
        // request offer rate
        usleep(delay_us);
    }
    
    // stop timer
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration = end - start;
    
    // report measurements
    auto average_latency_us = duration.count() / count_client_requests;
    std::cout << "average latency: " << average_latency_us << " us\n";
    
    // stop client
    client_stop();
    
}