/*
Algorithm:
1. Count the frequency of each element using an unordered map.
2. Store element-frequency pairs in a vector.
3. Sort the vector by frequency in descending order.
4. Extract the top k frequent elements from the sorted vector.
4. Return the result.
*/

#include <vector>
#include <unordered_map>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    // Comparator function to sort pairs by their frequency in descending order
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;  // Sort by frequency in decreasing order
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;  // Map to store the frequency of each element
        
        // Step 1: Count the frequency of each number in the input array
        for (auto x : nums) {
            mp[x]++;  // Increment the frequency of the element
        }

        vector<pair<int, int>> v;  // Vector to store pairs of elements and their frequencies
        
        // Step 2: Move elements and their frequencies from map to vector of pairs
        for (auto x : mp) {
            v.push_back(make_pair(x.first, x.second));
        }

        // Step 3: Sort the vector of pairs by their frequency in descending order
        sort(v.begin(), v.end(), cmp);

        vector<int> ans;  // Vector to store the result (top k frequent elements)
        
        // Step 4: Extract the top k frequent elements
        for (int i = 0; i < k; i++) {
            auto it = v.begin() + i;  // Get the i-th element from the sorted vector
            ans.push_back(it->first);  // Push the element (not the frequency) to the result
        }
        
        return ans;  // Return the result
    }
};
