#include <cstdlib>
#include "client.h"
#include "cache.h"


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    client_start("192.168.84.23:8080");
    
    // string response_string = client_request("memsize", "", "");
    // cout << "response string: " << response_string << endl;
    
    Cache* cache = new Cache(10, std::hash<std::string>());
    cache->set("k", "v", 1);
    cache->space_used();
    
    client_stop();
    
    return 0;
}

