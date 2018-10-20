#include <cstdlib>
#include <vector>

#include "cache.h"
#include "evictor_fifo.h"

FIFO::FIFO() {
    
}

void FIFO::push(Cache::key_type key) {
    stack.push_back(key);
}

Cache::key_type FIFO::get_next() {
    // get last element, remove it, then return it
    Cache::key_type key = stack.back();
    stack.pop_back();
    return key;
}

void FIFO::del(Cache::key_type key) {
    // erase anything that matches key
    stack.erase(
        std::remove(stack.begin(), stack.end(), key),
        stack.end());
}