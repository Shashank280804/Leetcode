/*
Algorithm:
1. Initialize Variables: Set maxSum to the smallest integer (INT_MIN) to handle negative numbers, and currentSum to 0.
2. Iterate through the Array: Loop through each element in the nums array.
3. Update Current Sum: Add the current element to currentSum.
4. Check for Maximum: If currentSum is greater than maxSum, update maxSum.
5. Reset if Negative: If currentSum becomes negative, reset it to 0 (since a negative sum wouldn't contribute to a larger sum).
6. Return Result: After iterating through the array, return maxSum.
*/

#include <bits/stdc++.h>
#include <limits.h> // Include limits.h to use INT_MIN
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN; // Initialize maxSum to the smallest possible integer
        int currentSum = 0; // Initialize currentSum to 0
        
        // Step 1: Iterate through each element in the array
        for (int i = 0; i < nums.size(); i++) {
            currentSum += nums[i]; // Add the current element to currentSum
            
            // Step 2: Update maxSum if currentSum is greater
            if (currentSum > maxSum) {
                maxSum = currentSum; // Update maxSum to currentSum
            }
            
            // Step 3: Reset currentSum to 0 if it drops below 0
            if (currentSum < 0) {
                currentSum = 0; // Reset currentSum as negative sums are not useful
            }
        }
        
        // Step 4: Return the maximum sum found
        return maxSum; // Return the maximum subarray sum
    }
};
