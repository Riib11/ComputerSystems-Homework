#include "client.h"
#include "cache.h"
#include <cstdlib>
#include <iostream>
#include <chrono>
#include <ctime>
#include <vector>

const std::string ADDRESS = "192.168.84.23:9082";

Cache::index_type max_memory = 256;
int key_size = 2;
int val_size = 2;
int count_client_requests = 128;

enum class Action { Set, Get, Del };

// generates a set of requests to run an experiment on,
// given the desired distribution of Cache actions
std::vector<std::pair<Action, Cache::key_type>> generate_requests(
    int count_so, // set old
    int count_sn, // set new
    int count_g,  // get
    int count_d)  // delete
{
    std::vector<std::pair<Action, Cache::key_type>> actions;
    
    // set ols
    for (int i = 0; i < count_so; i++) {
        // "old" is the key that all "set old" actions target
        actions.push_back(std::make_pair<Action, Cache::key_type>(Set, "old"));
    }
    // set new
    for (int i = 0; i < count_sn; i++) {
        // use "i" as the key
        actions.push_back(std::make_pair<Action, Cache::key_type>(Set, std::to_string(i)));
    }
    // get
    for (int i = 0; i < count_g; i++) {
        // always gets "old", which is gauranteed to be set
        actions.push_back(std::make_pair<Action, Cache::key_type(Get, "old"));
    }
    
    
    
    // always make sure there's at least one reference "old" (which is set first)
    actions.insert(actions.begin(), std::make_pair<Action, Cache::key_type>(Set, "old"))
    
    return actions;
}

void experiment1() {
    
    int offer_rate;
    int count_so = 256; // 1.00
    int count_sn = 0;   // 0.00
    int count_g  = 0;   // 0.00
    int count_d  = 0;   // 0.00

    // start client
    client_address(ADDRESS);
    client_start();
    
    Cache* cache = new Cache(256);
    
    
    
    // stop client
    client_stop();
    
}