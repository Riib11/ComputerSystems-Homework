#include <cstdlib>
#include <vector>
#include <memory>
#include <iostream>

#include "evictor_fifo.h"

FIFO::FIFO() {
    
}

void FIFO::push(key_type key_const) {
    std::string key = key_const;
    stack.insert(stack.begin(), key);
}

key_type FIFO::evict_next() {
    // get last element, remove it, then return it
    auto x = stack.size();
    key_type key = stack.back();
    stack.pop_back();
    std::cout << "evicting: " << key << "\n";
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