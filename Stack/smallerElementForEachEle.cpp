/*
1. Initialize a stack to keep track of elements.
2. Initialize a result array filled with -1.
3. Iterate through each element in the input array.
4. While the stack is not empty and the top element is greater than or equal to the current element, pop the stack.
5. If the stack is not empty after popping, the top element is the previous smaller element for the current element.
6. Push the current element onto the stack.
7. Return the result array containing the previous smaller elements or -1 where no smaller element exists.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> prevSmallerElements(vector<int>& nums) {
        stack<int> st;  // Stack to keep track of elements.
        int n = nums.size();
        vector<int> result(n, -1);  // Initialize the result vector with -1.

        // Iterate through each element in the array.
        for(int i = 0; i < n; i++) {
            // Check if the stack is not empty and the top element is greater than or equal to the current element.
            while(!st.empty() && st.top() >= nums[i]) {
                st.pop();  // Pop the stack until we find a smaller element.
            }

            // If the stack is not empty, the top element is the previous smaller element.
            if(!st.empty()) {
                result[i] = st.top();
            }

            // Push the current element onto the stack.
            st.push(nums[i]);
        }

        return result;  // Return the array of previous smaller elements.
    }
};

/*
Input: [4, 5, 2, 10, 8]

Steps:
For index 0 (value 4): Stack is empty, so result[0] = -1. Push 4 onto the stack.
For index 1 (value 5): Top of the stack (4) is less than 5, so result[1] = 4. Push 5 onto the stack.
For index 2 (value 2): Top of the stack (5) is greater than 2, pop it. Top of the stack (4) is also greater, pop it. Stack is empty, so result[2] = -1. Push 2 onto the stack.
For index 3 (value 10): Top of the stack (2) is less than 10, so result[3] = 2. Push 10 onto the stack.
For index 4 (value 8): Top of the stack (10) is greater than 8, pop it. Top of the stack (2) is less than 8, so result[4] = 2.
Output: [-1, 4, -1, 2, 2]
Input: [1, 6, 3, 4, 5]

Steps:
For index 0 (value 1): Stack is empty, so result[0] = -1. Push 1 onto the stack.
For index 1 (value 6): Top of the stack (1) is less than 6, so result[1] = 1. Push 6 onto the stack.
For index 2 (value 3): Top of the stack (6) is greater than 3, pop it. Top of the stack (1) is less than 3, so result[2] = 1.
For index 3 (value 4): Top of the stack (3) is less than 4, so result[3] = 3. Push 4 onto the stack.
For index 4 (value 5): Top of the stack (4) is less than 5, so result[4] = 4.
Output: [-1, 1, 1, 3, 4]
*/