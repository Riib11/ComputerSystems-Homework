#include <pistache/net.h>
#include <pistache/http.h>
#include <pistache/peer.h>
#include <pistache/http_headers.h>
#include <pistache/cookie.h>
#include <pistache/endpoint.h>

using namespace std;
using namespace Pistache;

class TestHandler : public Http::Handler {
public:

    HTTP_PROTOTYPE(TestHandler)

    void onRequest(const Http::Request& request, Http::ResponseWriter response) {
        UNUSED(request);
        response.send(Pistache::Http::Code::Ok, "this is a test\n");
    }
};