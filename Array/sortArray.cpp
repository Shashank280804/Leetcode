/*
1. Implement the mergeSort function to recursively divide the array into halves until each subarray has one element.
2. Use the merger function to combine two sorted subarrays into a single sorted array.
3. Continue merging until all subarrays are combined back into a sorted array.
4. Return the sorted array.
*/

#include <vector>
using namespace std;

class Solution {
public:
    // Function to merge two sorted subarrays
    void merger(vector<int>& nums, int start, int end) {
        int mid = start + (end - start) / 2;  // Find the midpoint
        int leftlen = mid - start + 1;  // Length of left subarray
        int rightlen = end - mid;  // Length of right subarray

        // Create temporary arrays for left and right subarrays
        vector<int> leftArray(leftlen);
        vector<int> rightArray(rightlen);

        int k = start;  // Start index for copying
        // Copy elements to left subarray
        for (int i = 0; i < leftlen; i++) {
            leftArray[i] = nums[k++];
        }

        // Copy elements to right subarray
        for (int i = 0; i < rightlen; i++) {
            rightArray[i] = nums[k++];
        }

        int leftInd = 0, rightInd = 0, mainInd = start;  // Initialize indices for merging
        // Merge the two subarrays back into the original array
        while (leftInd < leftlen && rightInd < rightlen) {
            if (leftArray[leftInd] < rightArray[rightInd]) {
                nums[mainInd++] = leftArray[leftInd++];  // Add from left subarray
            } else {
                nums[mainInd++] = rightArray[rightInd++];  // Add from right subarray
            }
        }

        // Copy any remaining elements from left subarray
        while (leftInd < leftlen) {
            nums[mainInd++] = leftArray[leftInd++];
        }

        // Copy any remaining elements from right subarray
        while (rightInd < rightlen) {
            nums[mainInd++] = rightArray[rightInd++];
        }
    }

    // Function to perform merge sort on the array
    void mergeSort(vector<int>& nums, int start, int end) {
        if (start >= end) {
            return;  // Base case: if the subarray has one or no elements
        }

        int mid = start + (end - start) / 2;  // Find the midpoint
        mergeSort(nums, start, mid);  // Sort the left half
        mergeSort(nums, mid + 1, end);  // Sort the right half

        merger(nums, start, end);  // Merge the sorted halves
    }

    // Main function to sort the array
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();  // Get the size of the array
        int start = 0, end = n - 1;  // Define the start and end indices
        mergeSort(nums, start, end);  // Call the mergeSort function
        return nums;  // Return the sorted array
    }
};

