/*
Algorithm:
1. Initialize left_Product and right_Product arrays to store cumulative products from the left and right.
2. Fill left_Product by calculating products of all elements to the left of the current index.
3. Fill right_Product by calculating products of all elements to the right of the current index.
4. Multiply corresponding elements of left_Product and right_Product to get the result for each index.
5. Return the result array.
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n); // Output array
        vector<int> left_Product(n); // Left cumulative product
        vector<int> right_Product(n); // Right cumulative product
        
        // Step 1: Initialize the first element of left_Product
        left_Product[0] = 1;
        // Step 2: Fill left_Product array
        for (int i = 1; i < n; i++) {
            left_Product[i] = left_Product[i - 1] * nums[i - 1]; // Calculate cumulative product from the left
        }
        
        // Step 3: Initialize the last element of right_Product
        right_Product[n - 1] = 1;
        // Step 4: Fill right_Product array
        for (int i = n - 2; i >= 0; i--) {
            right_Product[i] = right_Product[i + 1] * nums[i + 1]; // Calculate cumulative product from the right
        }
        
        // Step 5: Calculate the final result by multiplying left and right products
        for (int i = 0; i < n; i++) {
            ans[i] = left_Product[i] * right_Product[i];
        }
        
        return ans; // Return the final product array
    }
};
