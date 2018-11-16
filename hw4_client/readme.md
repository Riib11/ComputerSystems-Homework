# Homework 4: Let's Network!

Partners: Henry Blanchette and Henry Blanchette

## Dependencies

- [Pistache C++ REST framework](http://pistache.io/)

## 0: Preperation

After considering the tests of my peers, I think that my tests covered all of the relevant features of Cache. My actual Cache implementation from homework 3 had some bugs:
- `val_type Cache::get(key_type key, index_type& size) const` neither modified the given size nor maintained `const`.
- `void Cache::set(key_type key, val_type val, index_type size)` did not update the value sizes of keys that already existed.

I fixed each of these bugs in Homework 4's implimentation by changing the following:
- `Cache::get` now modifies the given size.
- `Cache` now declares `evictor_` to be `mutable`, so `Cache::get` can maintain `const`.
- `Cache::set` now updates the size of existing keys correctly

## 1: TCP Server

The server is run by `hw4_server/server.cpp`. Its critical structure is the class `Handler : Public Http::Handler` which, via the method `void onRequest(const Http::Request& req, Http::ResponseWriter response) override`, handles and responds to each request sent to the server by a client. It first processes the request's `resource` into a recognizable command and and arguments, and then runs the appropriate `Cache` method with the global `Cache` instance. Any expected results from the method run are packaged into a JSON string, which is then sent back to the client.

In addition to the normal `Cache` methods, the server also handles:
- `HEAD` sends the client an HTTP header with the HTTP version, Date, Accept, and Content-Type. For the most part this is automatically implimented by Pistache, and my `CacheHeader : public Http::Header::Header` class covers the Accept and Content-Type fields.
- `/shutdown` shuts down the server
- `/new` creates a new `Cache` instance in the global `cache` variable. This overwrites any existing `Cache` instance. There is only one active `Cache` at a time, no matter how many clients.

The server-side `Cache` is implimented in `hw4_server/cache.cpp`. It is exactly the same as the corrected hw3 `Cache`.

## 2: TCP Client

The client is run by `hw4_client/client.cpp`. The following functions are critical:

- `void client_address(std::string address_)` stores the given server address in a global variable, for the reference of subsequent client requests

- `string client_request(string command, string key, string value)` processes requests from the client to the server. `command` indicates the kind of request and`key` and `value` are arguments used in some of those requests. A tree of if-else branches determine which request to send to the server.

The client-size `Cache` is implimented in `hw4_client/cache.cpp`. It works by calling a `client_request` with the `command, key, value` parameters appropriate for the `Cache` method. `client_request` returns a string that can be interpretted as JSON that contains any return values the `Cache` method needs.