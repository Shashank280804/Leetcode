/*
Algorithm:
1. Calculate total sum of the array as rightSum.
2. Iterate through the array while maintaining leftSum.
3. For each index, update rightSum by subtracting the current element.
4. Check if leftSum equals rightSum; if true, return the current index as the pivot.
5. Update leftSum for the next iteration.
6. If no pivot is found after iterating, return -1.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int rightSum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            rightSum -= nums[i];
            
            if (leftSum == rightSum)
                return i;
           
            leftSum += nums[i];
        }
        return -1;
    }
};