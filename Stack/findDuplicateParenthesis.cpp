/*
1. Initialize a stack to store characters.
2. Traverse through the expression.
3. If a closing parenthesis is found, check how many elements are inside the parentheses.
4. If no or only one element is found between a pair of parentheses, it indicates a duplicate.
5. Return true if duplicates are found; otherwise, return false.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to check for duplicate parentheses in an expression.
    bool findDuplicateParenthesis(string expr) {
        stack<char> st;  // Stack to store characters from the expression.

        // Traverse each character of the expression.
        for(int i = 0; i < expr.length(); i++) {
            // If the character is a closing parenthesis ')'.
            if (expr[i] == ')') {
                int elementsInside = 0;  // Count of elements between a pair of parentheses.

                // Pop from stack until an opening parenthesis '(' is found.
                while (st.top() != '(') {
                    st.pop();
                    elementsInside++;
                }

                // Pop the opening parenthesis '('.
                st.pop();

                // If no or one element was between the parentheses, it's a duplicate.
                if (elementsInside < 1) {
                    return true;
                }
            }
            // If the character is not a closing parenthesis, push it to the stack.
            else {
                st.push(expr[i]);
            }
        }
        return false;  // Return false if no duplicate parentheses are found.
    }
};
/*
Iterations of input/output:
Input: "((a+b)+((c+d)))"
Steps:
Push '(', '(', 'a', '+', 'b', ')' onto the stack.
No duplicate found for first parentheses.
Push '+', '(', '(', 'c', '+', 'd', ')' onto the stack.
Duplicate found for second parentheses as only one '(' remains inside.
Output: true
Input: "(a+(b)/c)"

Steps:
Push '(', 'a', '+', '(', 'b', ')', '/', 'c', ')' onto the stack.
No duplicates found as all parentheses contain more than one element.
Output: false






*/