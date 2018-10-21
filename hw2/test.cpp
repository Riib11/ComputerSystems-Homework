#include <cstdlib>
#include <cassert>
#include <iostream>
#include <exception>

#include "cache.h"

using namespace std;

void pass(string name) {
    cout << "[*] PASSED " << name << "\n";
}

void fail(string name) {
    cout << "[X] FAILED " << name << "\n";
}

/*
 * Component tests
 */

// test vanilla cache functions (before part 5)
void vanilla_test() {
    
    Cache* cache = new Cache(4);
    
    // setting
    cache->set("a", "a", 2);
    cache->set("b", "b", 2);

    // getting
    cache->get("a", 2);
    cache->get("b", 2);
        
    // space used
    assert (cache->space_used() == 2 + 2);
    
    // eviction
    cache->set("c", "c", 1);
    assert (cache->space_used() == 3);
    
    // deleting
    cache->del("a");
    cache->del("c");
    assert (cache->space_used() == 0);
    
    pass("basic test");    
}

// eviction test (for any evictor)
void eviction_test() {
    Cache* cache = new Cache(2);
    
    cache->set("a", "a", 1);
    cache->set("b", "b", 1);
    cache->set("c", "c", 1);
    
    assert (cache->space_used() == 2);
        
    cache->get("a", 1);
    
    try {
        cache->get("a", 1);
        pass("eviction test");
    } catch(exception e) {
        fail("eviction test");
    }
}

// resizing test (part 5)
// requires: USING_RESIZING_ = true
void resizing_test() {
    
    Cache* cache = new Cache(2);
    
    cache->set("a", "a", 1);
    cache->set("b", "b", 1);
    assert (cache->space_used() == 2);
    
    cache->set("c", "c", 1);
    assert (cache->space_used() == 3);
    
    pass("resizing test");
}


/*
 * UNIT TEST
 */
void unit_test() {
    vanilla_test();
     eviction_test();
//    resizing_test();
    
    pass("unit test");
}