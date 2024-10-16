/*
1. Initialize a stack to store opening brackets.
2. Iterate through the string, pushing opening brackets onto the stack.
3. For each closing bracket, check if it matches the top of the stack; if yes, pop the stack.
4. If no match or stack is empty, return false.
5. After iteration, check if the stack is empty; return true if all brackets are valid, false otherwise.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<int> st;  // Initialize a stack to store opening brackets.
        
        for(int i=0; i<s.size(); i++) {
            // If the current character is an opening bracket, push it to the stack.
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } 
            // Else check if it's a closing bracket and if it matches the top of the stack.
            else {
                if(st.empty() == false) {  // Ensure the stack isn't empty.
                    // Check if the closing bracket matches the top opening bracket.
                    if(s[i] == ')' && st.top() == '(') st.pop();
                    else if(s[i] == '}' && st.top() == '{') st.pop();
                    else if(s[i] == ']' && st.top() == '[') st.pop();
                    // If there's a mismatch, return false.
                    else return false;
                } 
                // If the stack is empty and there's a closing bracket, return false.
                else return false;
            }
        }
        // After processing all characters, check if the stack is empty (all brackets matched).
        if(st.empty() == true) return true;
        return false;
    }
};

/*
Iterations of input/output:
Input: s = "()"

Steps:
( is pushed onto the stack.
) matches the top of the stack, so ( is popped.
Output: true (stack is empty)
Input: s = "()[]{}"

Steps:
Push (, then pop with ).
Push [, then pop with ].
Push {, then pop with }.
Output: true (stack is empty)
Input: s = "(]"

Steps:
Push (.
] does not match ( on the stack, so return false.
Output: false
Input: s = "([)]"

Steps:
Push (, then push [.
) does not match [, so return false.
Output: false
Input: s = "{[]}"

Steps:
Push {.
Push [, then pop with ].
Pop { with }.
Output: true (stack is empty)
*/