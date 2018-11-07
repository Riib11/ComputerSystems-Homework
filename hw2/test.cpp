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
// requires: USING_CUSTOM_EVICTION_ = false
//           USING_RESIZING_        = false
void vanilla_test() {
    string testname = "vanilla test";
    
    Cache* cache = new Cache(4);
    
    // setting
    cache->set("a", "a", 3);
    cache->set("b", "b", 1);

    // getting
    cache->get("a", 3);
    cache->get("b", 1);
        
    // space used
    assert (cache->space_used() == 3 + 1);
    
    // eviction (remove largest)
    cache->set("c", "c", 1);
    assert (cache->space_used() == 2);
    
    // deleting
    cache->del("b");
    cache->del("c");
    cache->space_used();
    assert (cache->space_used() == 0);
        
    cache = new Cache(3);
    
    cache->set("b", "b", 1);
    cache->set("a", "a", 2);
    cache->set("c", "c", 1);
    
    assert (cache->space_used() == 2);
    
    // should have evicted "a"
    if (cache->get("a", 2) == NULL) {
        pass(testname);
    } else {
        fail(testname);
    }
}

// test FIFO eviction (part 6)
// requires: USING_CUSTOM_EVICTION_ = true
//           eviction_obj_type      = FIFO
void eviction_FIFO_test() {
    string testname = "eviction FIFO test";
    
    Cache * cache = new Cache(3);
    
    cache->set("a", "a", 2);
    cache->set("b", "b", 1);
    cache->set("c", "c", 1);
    
    // should have evicted the "a"
    // as it was put in first
    
    if (cache->get("a", 2) == NULL) {
        pass(testname);
    } else {
        fail(testname);
    }
}

// test FIFO eviction (part 7)
// requires: USING_CUSTOM_EVICTION_ = true
//           eviction_obj_type      = LRU
void eviction_LRU_test() {
    string testname = "eviction LRU test";

    Cache * cache = new Cache(3);
    
    cache->set("a", "a", 1);
    cache->set("b", "b", 1);
    cache->set("c", "c", 1);
    
    // access the elements in different order
    cache->get("c", 1);
    cache->get("a", 1);
    cache->get("b", 1);
    
    // after this add, the evictor should remove "c"
    cache->set("d", "d", 1);
    
    if (cache->get("c", 1) == NULL) {
        pass(testname);
    } else {
        fail(testname);
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
    cout << "UNIT TEST:\n";
    vanilla_test();          // parts 1-4
    // resizing_test();         // part 5
    // eviction_FIFO_test();    // part 6
    // eviction_LRU_test();     // part 7
}