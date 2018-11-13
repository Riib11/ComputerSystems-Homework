#ifndef CLIENT_H
#define CLIENT_H

#include <pistache/net.h>
#include <pistache/http.h>
#include <pistache/client.h>
#include <cstdlib>

using namespace std;

void client_start(string address_);

void client_stop();

std::string client_request(string command, string key, string value);

#endif /* CLIENT_H */