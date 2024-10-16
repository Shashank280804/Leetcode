/*
Algorithm:
Step 1: Initialize a mp[] array of size 1,000,001 and set all elements to -1.
Step 2: For put(key, value), set mp[key] = value.
Step 3: For get(key), return mp[key] (or -1 if mp[key] == -1).
Step 4: For remove(key), set mp[key] = -1.
*/
class MyHashMap {
public:
int mp[1000001];
    MyHashMap() {
        for(int i =0;i<1000001;i++){
        mp[i]=-1;
    }
 }
    void put(int key, int value) {
        mp[key]=value;
    }
    
    int get(int key) {
        return mp[key];
    }
    
    void remove(int key) {
        mp[key]=-1;
    }
};

