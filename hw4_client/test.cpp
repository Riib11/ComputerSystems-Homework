#include "catch.h"
#include "client.h"
#include "cache.h"
#include <cstdlib>
#include <iostream>

const std::string ADDRESS = "192.168.84.23:9082";

TEST_CASE("Network Cache") {
    client_address(ADDRESS);
    client_start();
    
    //SECTION("Setting") {
        // construct cache (starts client)
        Cache* cache = new Cache(10);

        // set first key-value-size
        cache->set("a", "1", 1);

        // set subsequent key-value-size
        cache->set("b", "12", 2);
    //}

    //SECTION("Setting and Tracking Memory Used") {
        // construct cache (starts client)
        Cache* cache1 = new Cache(10);
        REQUIRE(cache1->space_used() == 0);

        // add first value
        cache1->set("a", "1", 1);
        REQUIRE(cache1->space_used() == 1);

        // add new value
        cache1->set("b", "1", 1);
        REQUIRE(cache1->space_used() == 2);

        // rewrite size of value
        cache1->set("a", "12", 2);
        REQUIRE(cache1->space_used() == 3);
    //}

    //SECTION("Evicting (arbitrary implementation)") {
        // construct cache (starts client)
        Cache* cache2 = new Cache(10);

        cache2->set("a", "12345", 5);
        cache2->set("b", "1234567890", 10);

        REQUIRE(cache2->space_used() <= 10);
    //}

    //SECTION("Respecting Max Memory") {
        // construct cache (starts client)
        Cache* cache3 = new Cache(10);

        cache3->set("a", "12345", 5);
        cache3->set("b", "12345", 5);
        REQUIRE(cache3->space_used() == 10);

        cache3->set("c", "12345", 5);
        REQUIRE(cache3->space_used() == 10);
    //}

    //SECTION("Getting") {
        // construct cache (starts client)
        Cache* cache4 = new Cache(10);
        Cache::index_type size1;

        // get newly added value
        cache4->set("a", "1", 1);
        cache4->get("a", size1);

        // get previous values
        cache4->set("b", "1", 1);
        cache4->get("b", size1);
        cache4->get("a", size1);
    //}

    //SECTION("Getting Size") {
        // construct cache (starts client)
        Cache* cache5 = new Cache(10);
        Cache::index_type size2;

        // retrieve size appropriately
        cache5->set("a", "1", 1);
        cache5->get("a", size2);
        REQUIRE(size2 == 1);

        // rewrite size appropriately
        cache5->set("a", "1234", 4);
        cache5->get("a", size2);
        REQUIRE(size2 == 4);
    //}

    //SECTION("Deleting") {
        // construct cache (starts client)
        Cache* cache6 = new Cache(10);
        Cache::index_type size3;

        cache6->set("a", "1", 1);
        cache6->set("b", "1234", 4);

        // deleting different values
        cache6->del("a");
        REQUIRE(cache6->get("a", size3) == NULL);
        cache6->del("b");
        REQUIRE(cache6->get("b", size3) == NULL);

        // re-add-del a deleted value
        cache6->set("a", "1", 1);
        cache6->del("a");
        REQUIRE(cache6->get("a", size3) == NULL);
    //}

    //SECTION("Deleting and Tracking Memory Used") {
        // construct cache (starts client)
        Cache* cache7 = new Cache(10);

        cache7->set("a", "1", 1);
        cache7->set("b", "1234", 4);

        cache7->del("a");
        REQUIRE(cache7->space_used() == 4);
        cache7->del("b");
        REQUIRE(cache7->space_used() == 0);

        // re-add-del a deleted value
        cache7->set("a", "1", 1);
        cache7->del("a");
        REQUIRE(cache7->space_used() == 0);
    //}

    client_stop();
}