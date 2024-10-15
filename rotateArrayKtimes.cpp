/*
Algorithm:
1. Reverse the Whole Array: Reverse all elements in the nums array.
2. Reverse from k to End: Reverse the elements from index k to the end of the array.
3. Reverse from Start to k-1: Reverse the elements from index 0 to k-1.
4. Final Output: The array is now rotated k steps to the right.
*/
#include <vector>
using namespace std;

class Solution {
public:
    // Step 1: Function to reverse elements in the vector from index i to j
    void reverse(vector<int>& nums, int i, int j) {
        while (i < j) {
            swap(nums[i++], nums[j--]); // Swap elements at positions i and j, then move towards the center
        }
    }

    // Step 2: Function to rotate the vector by k steps to the right
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(); // Get the size of the array
        k = k % n; // Normalize k to avoid unnecessary rotations

        // Step 3: Reverse the whole array
        reverse(nums, 0, n - 1);

        // Step 4: Reverse the array from k index to the end
        reverse(nums, k, n - 1);

        // Step 5: Reverse the array from the start to k-1 index
        reverse(nums, 0, k - 1);
    }
};

//1,2,3,4
//4,3,2,1
//4,3,1,2
//3,4,1,2