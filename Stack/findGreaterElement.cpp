/*
1. Initialize a stack to keep track of indices.
2. Iterate twice over the array to handle circular behavior.
3. For each element, check if it's greater than the element represented by the index at the top of the stack.
4. If it's greater, update the result for the element at the top of the stack and pop the stack.
5. Push the current element's index onto the stack and continue.
6. Return the result array containing the next greater elements or -1 where no greater element exists.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;  // Stack to keep track of indices of the elements.
        int n = nums.size();
        vector<int> result(n, -1);  // Initialize the result vector with -1.

        // Iterate twice over the array to handle circular nature.
        for(int i = 0; i < 2 * n; i++) {
            // Use modulo to simulate circular iteration.
            int index = i % n;

            // Check if current element is greater than the top element in the stack.
            while(!st.empty() && nums[st.top()] < nums[index]) {
                result[st.top()] = nums[index];  // Update the result for that element.
                st.pop();  // Pop the element from the stack.
            }

            // Push the index of the current element onto the stack.
            if (i < n) {
                st.push(index);
            }
        }

        return result;
    }
};

/*
Iterations of input/output:
Input: [1, 2, 1]

Steps:
Push index 0 (value 1) onto the stack.
Push index 1 (value 2) onto the stack.
Next greater for index 0 is 2.
Continue circular iteration to handle index 2.
No greater element for index 1.
Next greater for index 2 is 2.
Output: [2, -1, 2]
Input: [4, 5, 2, 25]

Steps:
Push index 0 (value 4) onto the stack.
Push index 1 (value 5) onto the stack.
Next greater for index 0 is 5.
Push index 2 (value 2) onto the stack.
Push index 3 (value 25) onto the stack.
Next greater for index 1 is 25.
Next greater for index 2 is 25.
Output: [5, 25, 25, -1]
*/