/*
Algorithm:
1. Sort the input array.
2. Initialize an empty set to store unique triplets.
3. Iterate through the array with index i, using two pointers j and k to find pairs that, along with nums[i], sum to zero.
4. Check if the sum of nums[i] + nums[j] + nums[k] is zero, and if so, add the triplet to the set; otherwise, adjust pointers j and k based on the sum.
5. Convert the set of triplets to a vector and return the result.
*/

#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target = 0;  // Target sum for the triplets
        sort(nums.begin(), nums.end());  // Step 1: Sort the array
        set<vector<int>> s;  // Set to store unique triplets
        vector<vector<int>> output;  // Vector to store the output
        
        // Step 2: Iterate through each element
        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1;  // Left pointer
            int k = nums.size() - 1;  // Right pointer
            
            // Step 3: Use two pointers to find pairs that sum to zero
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                
                // Step 4: If the sum equals the target, store the triplet
                if (sum == target) {
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;  // Move left pointer right
                    k--;  // Move right pointer left
                } 
                // If the sum is less than the target, move left pointer right
                else if (sum < target) {
                    j++;
                } 
                // If the sum is greater than the target, move right pointer left
                else {
                    k--;
                }
            }
        }
        
        // Step 5: Convert the set of triplets to a vector
        for (const auto& triplet : s) {
            output.push_back(triplet);
        }
        
        return output;  // Return the result
    }
};
