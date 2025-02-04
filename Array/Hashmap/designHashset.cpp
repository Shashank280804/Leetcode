/*
Algorithm:
Step 1: Initialize hash_table[] with size 1,000,001, setting all values to false.
Step 2: For add(key), set hash_table[key] = true.
Step 3: For remove(key), set hash_table[key] = false.
Step 4: For contains(key), return hash_table[key]
*/
#include <bits/stdc++.h>  // Include all standard C++ libraries
using namespace std;

class MyHashSet {
public:
    vector<bool> hash_table;  // Declare a boolean vector to represent the hash set

    MyHashSet() {
        // Initialize the vector with size 1000001, setting all values to false (indicating no elements)
        hash_table = vector<bool>(1000001, false);
    }
    
    void add(int key) {
        // Mark the index corresponding to 'key' as true (indicating the key is present)
        hash_table[key] = true;
    }
    
    void remove(int key) {
        // Mark the index corresponding to 'key' as false (indicating the key is removed)
        hash_table[key] = false;
    }
   
    bool contains(int key) {
        // Return true if the key is present, otherwise return false
        return hash_table[key] == true;
    }
};
