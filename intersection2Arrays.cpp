/*
1. Sort both input arrays, nums1 and nums2.
2. Initialize two pointers, i and j, to iterate through both arrays.
3. Compare elements pointed by i and j; if equal, check for duplicates before adding to the result.
4. If the element in nums1 is smaller, increment i; otherwise, increment j.
5. Continue until one of the pointers reaches the end of its array.
6. Return the resulting vector containing the intersection elements.
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;  // Initialize result vector to store intersection
        sort(nums1.begin(), nums1.end());  // Sort nums1
        sort(nums2.begin(), nums2.end());  // Sort nums2
        
        int i = 0, j = 0;  // Initialize pointers for both arrays
        while (i < nums1.size() && j < nums2.size()) {  // Iterate through both arrays
            if (nums1[i] == nums2[j]) {  // Check for equal elements
                // Add to result if not a duplicate
                if (result.empty() || result.back() != nums1[i]) {
                    result.push_back(nums1[i]);  // Add to result
                }
                i++;  // Move to the next element in nums1
                j++;  // Move to the next element in nums2
            } else if (nums1[i] < nums2[j]) {  // If current element in nums1 is smaller
                i++;  // Move to the next element in nums1
            } else {  // If current element in nums2 is smaller
                j++;  // Move to the next element in nums2
            }
        }
        
        return result;  // Return the result vector containing intersection elements
    }
};
