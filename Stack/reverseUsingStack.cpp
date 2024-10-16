/*
1. Initialize an empty stack to store characters.
2. Iterate through the string, pushing each character onto the stack.
3. Clear the string (vector) to prepare for the reversed output.
4. Pop each character from the stack and append it back to the string.
5. Return the reversed string.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to reverse a string using a stack.
    void reverseString(vector<char>& s) {
        stack<char> st;  // Initialize a stack to store characters.
        
        // Push each character from the string onto the stack.
        int i = 0;
        while(i < s.size()) {
            char ch = s[i];  // Get the current character.
            st.push(ch);     // Push it to the stack.
            i++;
        }
        
        s.clear();  // Clear the vector to store the reversed string.

        // Pop characters from the stack and append them back to the vector.
        while(!st.empty()) {
            char ch = st.top();   // Get the top element from the stack.
            s.push_back(ch);      // Append it to the vector.
            st.pop();             // Remove the top element from the stack.
        }
    }
};

/*
Iterations of input/output:
Input: ["h","e","l","l","o"]
Steps:
Push 'h', 'e', 'l', 'l', 'o' onto the stack.
Clear the vector.
Pop and append 'o', 'l', 'l', 'e', 'h' back to the vector.
Output: ["o","l","l","e","h"]
*/