#include <cache.h>
#include <cstdlib>
#include <unordered_map>
#include <map>
#include <iostream>
#include <vector>
#include <stdexcept>

#include "client.h"

#include <json.h>
using json = nlohmann::json;

using namespace std;

struct Cache::Impl {}; 


// Create a new cache object with a given max memory capacity
Cache::Cache(
    index_type maxmem,
    hash_func hasher)
{
    
}

// Cleanup cache
Cache::~Cache() {}

bool check_success(json response) {
    return response["success"] == "";
}

/*
 * Defer function calls to server
 */

int Cache::
set(key_type key, val_type val, index_type size) {
    const string* val_str_ptr = static_cast<const string*>(val);
    
    string val_str = new char[size+1];
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
    std::string response_string = client_request("get", key, "x");
    json response = json::parse(response_string);
    if (!check_success(response)) { return 0; } // error
    return 1; // no error
}

Cache::index_type Cache::
space_used() const {
    std::string response_string = client_request("memsize", "x", "x");
    json response = json::parse(response_string);
    if (!check_success(response)) {
        return 0;
    }
    return response["memused"];
}
