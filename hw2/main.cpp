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
//#include <cache.h>
#include <vector>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    vector<string> x;
    x = vector<string>(10);
    
    for (auto i = x.begin(); i != x.end(); ++i) {
        std::cout << *i << ",";
    }
        
    return 0;
}

