/*
1. Initialize a stack to store numbers.
2. Iterate through each token in the input.
3. If the token is a number, push it onto the stack.
4. If the token is an operator, pop two numbers from the stack, perform the operation, and push the result back.
5. At the end, the stack will contain the result at the top.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    stack<int> st;  // Stack to hold intermediate values during the evaluation.

    // Function to perform arithmetic operations.
    void operation(string& op) {
        if (st.empty()) return;  // If the stack is empty, return.

        // Pop the top two numbers from the stack.
        int n2 = st.top();
        st.pop();

        if (st.empty()) return;  // If there's no second number, return.

        int n1 = st.top();
        st.pop();

        // Perform the operation based on the operator.
        int result;
        switch(op[0]) {
            case '+': result = n1 + n2; break;
            case '-': result = n1 - n2; break;
            case '*': result = n1 * n2; break;
            case '/': result = n1 / n2; break;
        }
        // Push the result back onto the stack.
        st.push(result);
    }

    // Function to evaluate the Reverse Polish Notation.
    int evalRPN(vector<string>& tokens) {
        // Iterate through each token in the input.
        for(string& s : tokens) {
            // If the token is an operator, perform the operation.
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                operation(s);
            } 
            // Otherwise, it's a number, so push it onto the stack.
            else {
                int num = stoi(s);  // Convert the string to an integer.
                st.push(num);
            }
        }

        // The final result will be at the top of the stack.
        return st.top();
    }
};

/*
Iterations of input/output:
Input: ["2", "1", "+", "3", "*"]

Steps:
Push 2 onto the stack.
Push 1 onto the stack.
Perform 2 + 1 = 3, and push 3 onto the stack.
Push 3 onto the stack.
Perform 3 * 3 = 9, and push 9 onto the stack.
Output: 9
Input: ["4", "13", "5", "/", "+"]

Steps:
Push 4 onto the stack.
Push 13 onto the stack.
Push 5 onto the stack.
Perform 13 / 5 = 2, and push 2 onto the stack.
Perform 4 + 2 = 6, and push 6 onto the stack.
Output: 6
*/