/*
Algorithm:
Step 1: Initialize hash_table[] with size 1,000,001, setting all values to false.
Step 2: For add(key), set hash_table[key] = true.
Step 3: For remove(key), set hash_table[key] = false.
Step 4: For contains(key), return hash_table[key]
*/

#include <bits/stdc++.h>
using namespace std;
class MyHashSet {
public:
    vector<bool> hash_table;
    MyHashSet() {
        hash_table = vector<bool>(1000001, false);
    }
    
    void add(int key) {
        hash_table[key] = true;
    }
    
    void remove(int key) {
        hash_table[key] = false;
    }
   
    bool contains(int key) {
        return hash_table[key] == true;
    }
};