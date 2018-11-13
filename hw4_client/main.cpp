#include <cstdlib>
#include "client.h"


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    client_start("192.168.84.23:8080");
    
    client_request("memsize", "", "");
    
    client_stop();
    
    return 0;
}

