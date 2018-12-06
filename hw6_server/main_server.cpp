#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <getopt.h>
#include "server.h"
#include "cache.h"

using namespace std;

/*
 * 
 */
int main(int argc, char *argv[]) {

    // default arguments
    Cache::index_type maxmem = 1024;
    int portnum = 9082;
    
    // process command line arguments
    int opt;
    while((opt = getopt(argc, argv, "m:t:")) != -1) {
        switch(opt) {
            case 'm':
                maxmem = atoi(optarg);
                break;
            case 't':
                portnum = atoi(optarg);
                break;
            default:
                cout << "unrecognized command line argument: " << opt << endl;
                exit(EXIT_FAILURE);
        }
    }
    
    server_start(portnum, maxmem);
}