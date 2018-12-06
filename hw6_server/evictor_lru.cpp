#include <cstdlib>
#include <vector>
#include <memory>
#include <iostream>

#include "evictor_lru.h"

LRU::LRU() {
    
}

void LRU::push(key_type key_const) {
    std::string key = key_const;
    // std::cout << "pushing " << key << "\n";
    // remove other instances
    del(key);
    // put on top of stacks
    stack.push_back(key);
}

key_type LRU::evict_next() {
    // get bottom of stack
    key_type key = stack.front();
    // std::cout << "evicting " << key << "\n";
    // remove bottom of stack and all instances
    del(key);
    
    return key;
}

void LRU::del(key_type key_const) {
    std::string key = key_const;
    // std::cout << "deleting " << key << "\n";
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

void LRU::visit(key_type key_const) {
    std::string key = key_const;
    // std::cout << "visiting " << key << "\n";
    // remove from any other instances in stack
    del(key_const);
    // push to end
    stack.push_back(key);
}