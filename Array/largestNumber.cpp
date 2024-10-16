/*
1. Use a nested loop to compare pairs of numbers and determine their order based on string concatenation.
2. Swap the numbers if the concatenation of the second number with the first is greater than that of the first with the second.
3. Construct the final string by concatenating the sorted numbers.
4. Handle the case where the result starts with '0' to return "0" if all numbers are zero.
*/
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans;  // Initialize an empty string to store the result
        // Iterate through the array to sort numbers based on custom criteria
        for (int i = 0; i < nums.size(); i++) {
            // Compare current number with subsequent numbers
            for (int j = i + 1; j < nums.size(); j++) {
                // Create string representations of the concatenations
                string strj = to_string(nums[j]) + to_string(nums[i]);
                string stri = to_string(nums[i]) + to_string(nums[j]);
                // If strj is greater than stri, swap the numbers
                if (strj > stri) swap(nums[j], nums[i]);
            }
            // Append the current number to the result string
            ans += to_string(nums[i]);
        }
        // Check if the result starts with '0', return "0" if all numbers are zero
        return ans[0] == '0' ? "0" : ans;
    }
};
