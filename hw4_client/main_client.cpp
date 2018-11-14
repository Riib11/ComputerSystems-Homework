#include <cstdlib>
#include "client.h"
#include "cache.h"


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    client_start("192.168.84.23:9081");
    
    Cache* cache = new Cache(100, std::hash<std::string>());
    
    Cache::key_type key = "key1";
    string val_str = "value1";
    Cache::val_type val = &val_str;
    
    cache->set("k", val, val_str.length());
    
    cache->space_used();
    
    client_stop();
    
    return 0;
}

