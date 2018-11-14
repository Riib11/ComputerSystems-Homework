#include <cstdlib>
#include "client.h"


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    client_start("192.168.84.23:8080");
    
    // string response_string = client_request("memsize", "", "");
    // cout << "response string: " << response_string << endl;
    
    client_stop();
    
    return 0;
}

