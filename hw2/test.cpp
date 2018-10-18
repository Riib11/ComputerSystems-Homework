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

// test basic cache functions
void basic_test() {
    
    Cache* cache = new Cache(6);
    
    Cache::key_type k0 = "a";
    Cache::val_type v0 = "a";
    Cache::index_type s0 = 1;
    
    Cache::key_type k1 = "b";
    Cache::val_type v1 = "b";
    Cache::index_type s1 = 2;
    
    // setting
    cache->set(k0, v0, s0);
    cache->set(k1, v1, s1);
                
    // getting
    cache->get(k0, s0);
    cache->get(k1, s1);
        
    // space used
    assert (cache->space_used() == s0 + s1);
    
    // deleting
    cache->del(k0);
    cache->del(k1);
    assert (cache->space_used() == 0);
    
    pass("basic test");    
}

// eviction test
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

// resizing test
void resizing_test() {
    
    Cache* cache = new Cache(2);
    
    cache->set("a", "a", 1);
    cache->set("b", "b", 1);
//    cout << "space used = " << cache->space_used() << "\n";
    assert (cache->space_used() == 2);
    
    cache->set("c", "c", 1);
//    cout << "space used = " << cache->space_used() << "\n";
    assert (cache->space_used() == 3);
    
    pass("resizing test");
}


/*
 * UNIT TEST
 */
void unit_test() {
    basic_test();
    // eviction_test();
    resizing_test();
    
    pass("unit test");
}