/*
Algorithm:
1. Handle empty input: Return 0 if the input array is empty.
2. Sort the array.
3. Iterate through sorted array: Track current consecutive sequence length, reset if non-consecutive.
4. Handle duplicates: Skip duplicates without resetting the sequence length.
5. Update maximum length: Keep track of the longest sequence during the iteration.
6. Return the maximum length.
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        sort(nums.begin(), nums.end());  // Sort the numbers

        int maxLength = 1;  // Store the maximum length of consecutive sequence
        int currentLength = 1;  // Store the current length of consecutive sequence

        for (int i = 1; i < nums.size(); i++) {
            // If the current number is consecutive to the previous one
            if (nums[i] == nums[i - 1] + 1) {
                currentLength++;
            }
            // If the current number is the same as the previous, we skip
            else if (nums[i] != nums[i - 1]) {
                // Reset the current length for a new sequence
                currentLength = 1;
            }

            // Update the maximum length found so far
            maxLength = max(maxLength, currentLength);
        }

        return maxLength;  // Return the maximum consecutive sequence length
    }
};
