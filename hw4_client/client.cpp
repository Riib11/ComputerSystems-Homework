#include <unistd.h>
#include <getopt.h>

#include <atomic>

#include <pistache/net.h>
#include <pistache/http.h>
#include <pistache/client.h>

using namespace Pistache;
using namespace Pistache::Http;

#include <json.h>
using json = nlohmann::json;

int main(int argc, char *argv[]) {
    
    // parse command line options
    int opt;
    std::string address, command, key, value;
    while((opt = getopt(argc, argv, "a:c:k:v:")) != -1) {
        switch(opt) {
            // server address
            case 'a':
                address = optarg;
                break;
            case 'c':
                command = optarg;
                break;
            case 'k':
                key = optarg;
                break;
            case 'v':
                value = optarg;
                break;
            default:
                std::cout << "unrecognized command line argument: " << opt << std::endl;
                exit(EXIT_FAILURE);
        }
    }
    
    // debug command line parse
    std::cout
            << std::endl
            << "-----------------------"    << std::endl
            <<  "address: " << address      << std::endl
            <<  "command: " << command      << std::endl
            <<      "key: " << key          << std::endl
            <<    "value: " << value        << std::endl
            << "-------------------------"  << std::endl;
    
    exit(0);
            
    // declare client
    Http::Client client;
    Http::RequestBuilder response;

    // Http client options
    auto opts = Http::Client::options()
            .threads(1)
            .maxConnectionsPerHost(8);
    client.init(opts);
    
    // send request
    if (command == "get") {
        response = client.get(address + "/key/" + key).cookie(Http::Cookie("FOO", "bar")).send();
    } else if (command = "memsize") {
        response = client.get(address + "/" + memsize);
    } else {
        std::cout << "unrecognized command: " << command << std::endl;
        exit(EXIT_FAILURE);
    }
    
    // report response
    response.then([&](Http::Response response) {
        std::cout << "Response code = " << response.code() << std::endl;
        auto body = response.body();
        if (!body.empty()) {
            std::cout << "Response body = " << body << std::endl;
        }
    }, Async::IgnoreException);
    
    // shutdown client
    client.shutdown();
}