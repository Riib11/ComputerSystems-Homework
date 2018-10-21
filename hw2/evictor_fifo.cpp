#include <cstdlib>
#include <vector>
#include <memory>

#include "evictor_fifo.h"

FIFO::FIFO() {
    
}

void FIFO::push(key_type key_const) {
    std::string key = key_const;
    stack.push_back(key);
}

key_type FIFO::get_next() {
    // get last element, remove it, then return it
    key_type key = stack.back();
    stack.pop_back();
    return key;
}

void FIFO::del(key_type key_const) {
    std::string key = key_const;
    std::vector<std::string> stack_new;
    // filter out everything with the given key
    for (std::string k : stack) {
        if (k != key) {
            stack_new.push_back(k);
        }
    }
    // update stack
    stack = stack_new;
}