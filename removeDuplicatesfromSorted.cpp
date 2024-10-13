#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Step 1: Check if the input vector is empty
        if (nums.empty()) {
            return 0; // If empty, return 0 as there are no elements
        }

        int k = 1; // Step 2: Initialize a counter for unique elements
        // Step 3: Iterate through the vector starting from the second element
        for (int i = 1; i < nums.size(); ++i) {
            // Step 4: Check if the current element is different from the previous one
            if (nums[i] != nums[i - 1]) {
                nums[k++] = nums[i]; // Step 5: Update the position of unique elements and increment k
            }
        }

        return k; // Step 6: Return the count of unique elements
    }
};
