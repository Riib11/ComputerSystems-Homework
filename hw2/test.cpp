#include <cstdlib>
#include <cassert>
#include <iostream>
#include "cache.h"

/*
 * UNIT TEST
 */
void unit() {
    
}

// test basic cache functions
void basic() {
    
    Cache* cache = new Cache(6);
    
    // setting
    cache->set("a", "a", 1);
    cache->set("b", "b", 2);
    cache->set("c", "c", 3);
    
    // getting
    cache->get("a", 1);
//    assert (cache->get("a", 1) == "a");
//    assert (cache->get("b", 2) == "b");
//    assert (cache->get("c", 3) == "c");
    
    // space used
    assert (cache->space_used() == 6);
    
    // deleting
    cache->del("a");
    cache->del("b");
    cache->del("c");
    assert (cache->space_used() == 0);
    
}