#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Hash map to store cumulative sum frequencies
        unordered_map<int, int> m;
        m[0] = 1;  // Initialize with 0 sum occurring once
        
        int sum = 0;
        int ans = 0;
        
        // Traverse the array
        for (auto x : nums) {
            sum += x;  // Update cumulative sum
            
            // Check if (sum - k) exists in the map
            if (m.find(sum - k) != m.end()) {
                ans += m[sum - k];  // Add the count of subarrays that sum to k
            }
            
            // Update the frequency of the current cumulative sum
            m[sum]++;
        }
        
        return ans;  // Return the total number of subarrays
    }
};