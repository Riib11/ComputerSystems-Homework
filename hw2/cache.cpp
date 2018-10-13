/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "cache.h"
#include <cstdlib>
#include <vector>

class Cache::Impl {

    index_type maxmem_;    //
    index_type memused_;   //
    evictor_type evictor_; // () -> index_type
    hash_func hasher_;     // key_type -> index_type (in internal data)
    
    vector<val_type> memory;
    vector<key_type> stack;
    index_type stack_head;
    
public:
    
    Impl(index_type maxmem, evictor_type evictor, hash_func hasher)
    : maxmem_(maxmem), evictor_(evictor), hasher_(hasher), memused_(0) {
        
    }
    
    void
    set(key_type key, val_type val, index_type size) {
        // TODO
    } 
    val_type
    get(key_type key, index_type size) {
        // TODO
    }
    
    void
    del(key_type key) {
        // TODO
    }
    
    index_type
    space_used() const {
        // TODO
    }
    
};

// Create a new cache object with a given max memory capacity
Cache::Cache(
index_type maxmem,
evictor_type evictor,
hash_func hasher)
: pImpl_(new Impl(maxmem, evictor, hasher)) {
    
}

// Cleanup cache
Cache::~Cache() {
    
}

/*
 * Defer function calls to Impl
 */

void
Cache::set(key_type key, val_type val, index_type size) {
    pImpl_->set(key, val, size);
}

Cache::val_type
Cache::get(key_type key, index_type& size) const {
    pImpl_->get(key, size);
}

void
Cache::del(key_type key) {
    pImpl_->del(key);
}

Cache::index_type
Cache::space_used() const {
    pImpl_->space_used();
}
