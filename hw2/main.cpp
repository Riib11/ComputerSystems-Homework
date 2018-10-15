/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: henry
 *
 * Created on October 8, 2018, 1:09 PM
 */

#include <cstdlib>
#include <cache.h>
#include <vector>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Cache::key_type key    = "k";
    Cache::val_type val  = "v";
    Cache::index_type size = 1;
    
    // test setting and getting
    Cache* cache = new Cache(10);
    cache->set(key, val, size);
    Cache::val_type x = cache->get(key, size);
    
    // TODO: returns an address, but can't de-reference?
    //       the problem seems to have to do with the cost void* type
    cout << x;
    
    return 0;
}

