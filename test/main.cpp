/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: henry
 *
 * Created on October 15, 2018, 1:01 PM
 */

#include <cstdlib>
#include <iostream>
#include <unordered_map>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    unordered_map<string, pair<int,int>> map;
    map["a"] = make_pair(1,1);
    map["b"] = make_pair(2,2);
    
    if (map.find("x") == map.end()) {
        cout << "not found\n";
    }

    for (auto& x : map) {
        cout << x.first << " : "
                << x.second.first << ", "
                << x.second.second << "\n";
    }
    
    return 0;
}

