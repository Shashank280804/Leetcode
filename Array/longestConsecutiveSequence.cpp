#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        sort(nums.begin(), nums.end());

        int maxLength = 1;
        int currentLength = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                currentLength++;
            }
            else if (nums[i] != nums[i - 1]) {
                currentLength = 1;
            }

            maxLength = max(maxLength, currentLength);
        }

        return maxLength;
    }
};
