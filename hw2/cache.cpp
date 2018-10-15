/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cache.h>
#include <cstdlib>
#include <unordered_map>
#include <map>


class Cache::Impl {

    index_type   maxmem_;   //
    index_type   memused_;  // 
    evictor_type evictor_;  // () -> index_type
    hash_func    hasher_;   // key_type -> index_type
    
    std::map<key_type, val_type>
    memory_; // key => value
    std::map<key_type, std::pair<val_type, index_type>>
    cache_; // key => value, size
    
public:
        
    Impl(index_type maxmem, evictor_type evictor, hash_func hasher)
    : maxmem_(maxmem), evictor_(evictor), hasher_(hasher), memused_(0) {        

    }
    
    void
    del_smallest() {
        // find the key of the smallest value
        index_type size_min = 0;
        key_type * key_min;
        for (auto& it : cache_) {
            key_type    key = it.first;
            index_type size = it.second.second;
            if (size < size_min) {
                size_min = size;
                key_min  = &key;
            }
        }
        // delete the smallest value from the cache
        cache_.erase(*key_min);
    }
    
    void
    set(key_type key, val_type val, index_type size) {
        // key not already in cache
        if (cache_.find(key) == cache_.end()) {
            // cache is full
            if (memused_ == maxmem_) {
                // so remove smallest value
                del_smallest();
                // then add new value
                cache_[key] = std::make_pair(val, size);
            }
            // cache isn't full, so add new value
            else {
                cache_[key] = std::make_pair(val, size);
            }
        }
        // key is already in cache, so change to new value
        else {
            cache_[key] = std::make_pair(val, size);
        }
    }
    
    val_type
    get(key_type key, index_type size) {
        return cache_[key].first;
    }
    
    void
    del(key_type key) {
        cache_.erase(key);
    }
    
    index_type
    space_used() const {
        return memused_;
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
