#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

class Solution
{
    vector<int> concatenateArray(vector<int> nums)
    {
        int n = nums.size();
        vector<int> ans(2 * n);
        for(int i=0;i<n;i++){
            ans[i]=nums[i];
            ans[i+n]=nums[i];
        }
        return ans;
    }
};