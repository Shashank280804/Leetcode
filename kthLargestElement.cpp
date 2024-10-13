/*
Algorithm:
1. Sort the Array: Sort the nums array in ascending order.
2. Determine Length: Store the length of the sorted array.
3. Calculate Index: Compute the index of the kth largest element as length - k.
4. Return Element: Return the element at the computed index.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int length; // Step 1: To store the size of the input array
    int i;      // Step 2: To store the index of the kth largest element

    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); // Step 3: Sort the array in ascending order
        length = nums.size();            // Step 4: Get the size of the array
        i = length - k;                  // Step 5: Calculate the index of the kth largest element
        return nums[i];                  // Step 6: Return the kth largest element
    }
};
