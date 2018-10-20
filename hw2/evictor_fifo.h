#include "cache.h"
#include <cstdlib>
#include <vector>

/*
 * FIFO: first in first out eviction policy
 * 
 * is basically just a modified stack
 */
class FIFO {
    
    FIFO();
    
    std::vector<key_type> stack;
    
    // add an item to keep track of
    void push(key_type key);
    
    // get next item to evict
    Cache::key_type get_next();
    
    // remove an item being tracked
    void del(key_type key);
    
};