#include "catch.h"
#include "cache.h"
#include <cstdlib>
#include <iostream>

TEST_CASE("Construction", "[constructor]") {
    // constructs cache without error
    Cache* cache = new Cache(10);
}

TEST_CASE("Setting", "[set]") {
    Cache* cache = new Cache(10);
    
    // set first key-value-size
    cache->set("a", "a", 1);
    
    // set subsequent key-value-size
    cache->set("b", "b", 2);
}

TEST_CASE("Setting and Memory", "[constructor, set, memused]") {
    Cache* cache = new Cache(10);
    REQUIRE( cache->space_used() == 0 );
    
    // add first value
    cache->set("a", "a", 1);
    REQUIRE( cache->space_used() == 1 );
    
    // add new value
    cache->set("b", "b", 1);
    REQUIRE( cache->space_used() == 2 );
    
    // rewrite size of value
    cache->set("a", "a", 2);
    REQUIRE( cache->space_used() == 3 );
}

TEST_CASE("Max Memory Respected", "[constructor, set, memused, memmax]") {
    Cache* cache = new Cache(10);
    
    cache->set("a", "a", 5);
    cache->set("b", "b", 5);
    REQUIRE( cache->space_used() == 10 );
    
    cache->set("c", "c", 5);
    REQUIRE( cache->space_used() == 10 );
}

TEST_CASE("Memory Updated", "[constructor, set, memused]") {
    Cache* cache = new Cache(10);
    
    cache->set("a", "a", 10);
    
    // update entry size
    cache->set("a", "a", 5);
    REQUIRE( cache->space_used() == 5 );
    
    // allows for filling up to memmax
    // after size update
    cache->set("b", "b", 5);
    REQUIRE( cache->space_used() == 10 );
    
}

TEST_CASE("Getting", "[constructor, set, get]") {
    Cache* cache = new Cache(10);
    
    // get newly added value
    cache->set("a", "a", 1);
    cache->get("a", 1);
    
    // get previous values
    cache->set("b", "b", 1);
    cache->get("b", 1);
    cache->get("a", 1);
}

TEST_CASE("Getting Size", "[constructor, set, get, size]") {
    Cache* cache = new Cache(10);
    
    // retrieve size appropriately
    cache->set("a", "a", 1);
    index_type size;
    cache->get("a", &size);
    REQUIRE( size == 1 );
    
    // rewrite size appropriately
    cache->set("a", "b", 4);
    cache->get("a", &size);
    REQUIRE( size == 4 );
    
}

TEST_CASE("Deleting", "[constructor, set, del]") {
    Cache* cache = new Cache(10);
    
    cache->set("a", "a", 1);
    cache->set("b", "b", 4);
    
    // deleting different values
    cache->del("a");
    REQUIRE( cache->get("a", 1) == NULL );
    cache->del("b");
    REQUIRE( cache->get("b", 4) == NULL );
    
    // re-add-del a deleted value
    cache->set("a", "a", 1);
    cache->del("a");
    REQUIRE( cache->get("a", 1) == NULL );
}

TEST_CASE("Deleting and Memory", "[constructor, set, del, memused]") {
    Cache* cache = new Cache(10);
    
    cache->set("a", "a", 1);
    cache->set("b", "b", 4);
    
    cache->del("a");
    REQUIRE( cache->space_used() == 4 );
    cache->del("b");
    REQUIRE( cache->space_used() == 0 );
    
    // re-add-del a deleted value
    cache->set("a", "a", 1);
    cache->del("a");
    REQUIRE( cache->space_used() == 0 );
}