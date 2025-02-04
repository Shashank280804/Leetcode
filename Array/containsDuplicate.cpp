/*
Step 1: Sort the nums array.
Step 2: Iterate from i = 0 to nums.size() - 2.
Step 3: If nums[i] == nums[i+1], return true.
Step 4: Return false if no duplicates are found.
*/

#include <bits/stdc++.h>  // Includes all standard C++ libraries

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int> nums) {  
        bool flag = false;  // Initialize a flag (not used effectively)

        sort(nums.begin(), nums.end());  // Sort the vector in ascending order

        for (int i = 0; i < nums.size() - 1; i++) {  // Iterate through the array until the second last element
            if (nums[i] == nums[i + 1]) {  // If two consecutive elements are the same
                return true;  // Return true indicating a duplicate exists
            }
            return false;  // Incorrect: This causes the function to return false after the first iteration
        }
    }
};
