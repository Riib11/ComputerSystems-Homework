#include <cstdlib>
#include <iostream>

#define CATCH_CONFIG_MAIN
#include "catch.h"

/*
#include <cstdlib>
#include "client.h"
#include "cache.h"

using namespace std;

int main(int argc, char** argv) {

    client_address("192.168.84.23:9081");

    // construct cache (starts client)
    Cache* cache = new Cache(10);

    // set first key-value-size
    const char* s = "1";
    const void* s_vptr = s;
    cache->set("a", s_vptr, 2);

    // set subsequent key-value-size
//    cache->set("b", "12", 2);

    // descruct cache (stop client)
    cache->~Cache();

    exit(EXIT_SUCCESS);
}
*/