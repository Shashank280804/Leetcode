#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> numSet(nums.begin(), nums.end());
        vector<int> result;

        for (int i = 1; i <= n; ++i) {
            if (numSet.find(i) == numSet.end()) {
                result.push_back(i);
            }
        }
        
        return result;
    }


};