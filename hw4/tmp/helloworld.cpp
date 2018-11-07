#include <pistache/endpoint.h>

using namespace Pistache;

// handler - handles requests
struct HelloHandler : public Http::Handler {
    HTTP_PROTOTYPE(HelloHandler)

    void onRequest(
        const Http::Request& request,
        Http::ResponseWriter writer)
    {
        writer.send(Http::Code::Ok, "Hello, World!");
    }
};

// starts server
int main() {
    // defaults to using just 1 thread
    Http::listenAndServe<HelloHandler>("*:9080");
}