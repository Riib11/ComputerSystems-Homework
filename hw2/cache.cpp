/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "cache.h"
#include <cstdlib>
#include <vector>
#include <iostream>
#include <unordered_map>

class Cache::Impl {

    index_type maxmem_;    //
    index_type memused_;   //
    evictor_type evictor_; // () -> index_type
    hash_func hasher_;     // key_type -> index_type (in index_cache)
    
public:
    
    std::vector<val_type> memory_;
    std::vector<index_type> index_cache_;
    std::vector<index_type> size_cache_;
    
    index_type index_cache_default_;
        
    Impl(index_type maxmem, evictor_type evictor, hash_func hasher)
    : maxmem_(maxmem), evictor_(evictor), hasher_(hasher), memused_(0) {
        // initialize cache memory
        index_cache_ = std::vector<index_type>(maxmem);
        size_cache_  = std::vector<index_type>(maxmem);
        index_cache_default_ = index_cache_[0];
    }
    
    void
    set(key_type key, val_type val, index_type size) {
        memory_.push_back(val);                     // put new val in memory
        index_type i_cache    = hasher_(key);       // index in cache
        index_type i_memory   = memory_.size();     // index of new val in memory
        index_cache_[i_cache] = i_memory;           // index_cache has index in memory
        size_cache_[i_cache]  = size;               // size_cache has size of val
    }
    
    val_type
    get(key_type key, index_type size) {
        index_type i_cache  = hasher_(key);         // get index in cache
        index_type i_memory = index_cache_[i_cach]; // get index in memory (value in index_cache)
        return memory_[i_memory];                   // get value in memory
    }
    
    void
    del(key_type key) {
        index_type i_cache = hasher_(key);            // get index in cache
        index_cache_[i_cache] = index_cache_default_; // reset the index_cache value
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
