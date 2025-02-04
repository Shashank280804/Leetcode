/*
Step 1: Get the size n of the input array.
Step 2: Create a new vector ans of size 2 * n.
Step 3: Iterate through nums from i = 0 to n - 1.
Step 4: Assign ans[i] = nums[i] and ans[i + n] = nums[i].
Step 5: Return ans.
*/


#include <iostream>       // For input/output operations
#include <vector>         // For using the vector container
#include <bits/stdc++.h>  // Includes all standard C++ libraries
#include <algorithm>      // For using algorithms like sorting

using namespace std;

class Solution {
public:
    vector<int> concatenateArray(vector<int>& nums) {  
        int n = nums.size();  // Get the size of the input array

        vector<int> ans(2 * n);  // Create a new vector of size 2*n to store the concatenated result

        for (int i = 0; i < n; i++) {  // Iterate through the original array
            ans[i] = nums[i];     // Copy the element at index 'i' from 'nums' to 'ans'
            ans[i + n] = nums[i]; // Copy the same element at index 'i + n' to repeat the array
        }

        return ans;  // Return the concatenated array
    }
};
