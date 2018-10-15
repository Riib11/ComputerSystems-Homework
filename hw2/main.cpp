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
    auto key = "k";
    const void* val = "v";

    Cache* cache = new Cache(10);
    cache->set("k", "v", 1);
    
    cout << "used " << cache->space_used() << " slots";
    
    return 0;
}

