/*
Step 1: Initialize i = 0 and j = 0.
Step 2: Iterate while i < n.
Step 3: If nums[i] is non-zero, swap nums[i] with nums[j] and increment j.
Step 4: Increment i.
Step 5: Repeat until the end of the array.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {  
        int n = nums.size(); // Get the size of the array
        int i = 0, j = 0;    // Two pointers: i to traverse, j to track non-zero position

        while (i < n) {  // Iterate through the array
            if (nums[i] != 0) {  // If the current element is non-zero
                swap(nums[i], nums[j]);  // Swap it with the element at position j
                j++;  // Move j to the next position for the next non-zero element
            }
            i++;  // Move to the next element
        }
    }
};
