/*
Algorithm:
1. Check for Empty Array: If nums is empty, return 0.
2. Initialize Counter: Set k to 1 to track the position of unique elements.
3. Iterate Through Array: Loop through nums starting from the second element.
4. Check for Uniqueness: If the current element is not equal to the previous element, assign it to nums[k] and increment k.
5. Return Count: After the loop, return the value of k as the count of unique elements.

*/
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
