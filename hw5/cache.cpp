#include <cstdlib>
#include <unordered_map>
#include <map>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <inttypes.h>
#include <stdio.h>
#include <chrono>
#include <thread>

#include "cache.h"
#include "client.h"

#include "json.h"
using json = nlohmann::json;

using namespace std;

struct Cache::Impl {}; 

bool check_success(json response) {
    return response["success"] == "true";
}

// Create a new cache object with a given max memory capacity
Cache::Cache(
    index_type maxmem,
    hash_func hasher)
{
    // start client
//    client_start();
    // tell server to start
    string response_string = client_request("new", to_string(maxmem), "");
    json response = json::parse(response_string);
    if (!check_success(response)) { throw std::invalid_argument("failure in creating cache"); } // error
}

// Cleanup cache
Cache::~Cache() {
    // stop client
    client_stop();
    // wait a second to prevent collision with subsequent cache creations
    this_thread::sleep_for(std::chrono::milliseconds(1000));
}

/*
 * Defer function calls to server
 */

int Cache::
set(key_type key, val_type val, index_type size) {
    const char** val_str_ptr = reinterpret_cast<const char**>(&val);
    const char* val_str = new char[size+1];
    val_str = *val_str_ptr;
    
    // DEBUG
    // cout << "val_str = [" << val_str << "]" << endl;
    
    string response_string = client_request("set", key, val_str);
    json response = json::parse(response_string);
    if (!check_success(response)) { return 1; } // error
    return 0; // no error
}

Cache::val_type Cache::
get(key_type key, index_type& val_size) const {
    std::string response_string = client_request("get", key, "x");
    json response = json::parse(response_string);
    if (!check_success(response)) { // error
        val_size = 0;
        return NULL;
    }
    // no error
    val_size = response["val_size"];
    // cast to val_type
    std::string val_string = response["value"];
    std::string* val_string_ptr = &val_string;
    Cache::val_type val = val_string_ptr;
    return val;
}

int Cache::
del(key_type key) {
    std::string response_string = client_request("del", key, "x");
    json response = json::parse(response_string);
    if (!check_success(response)) { return 0; } // error
    return 1; // no error
}

Cache::index_type Cache::
space_used() const {
    std::string response_string = client_request("memsize", "x", "x");
    json response = json::parse(response_string);
    if (!check_success(response)) { return 0; }
    return response["memused"];
//    
//    
//    // cast: string -> int32_t
//    Cache::index_type x;
//    const char* cstr = ((string) response["memused"]).c_str();
//    sscanf(cstr, "%" SCNu32, &x);
//    return x;
}
