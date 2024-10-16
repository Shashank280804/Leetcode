/*
1. Initialize a stack that stores pairs of the value and the current minimum.
2. For `push`, store the value along with the minimum of the current value and the previous minimum.
3. For `pop`, remove the top element from the stack.
4. For `top`, return the first element of the pair at the top of the stack (the value).
5. For `getMin`, return the second element of the pair at the top of the stack (the minimum).

*/

#include<bits/stdc++.h>
using namespace std;

class MinStack {
public:
    vector<pair<int, int>> st;  // Vector to store pairs: (value, current minimum).

    // Constructor to initialize the MinStack.
    MinStack() {
        // No explicit initialization needed here.
    }
    
    // Push a new value onto the stack.
    void push(int val) {
        if(st.empty()) {
            // If the stack is empty, the current value is the minimum.
            pair<int, int> p;
            p.first = val;   // Store the value.
            p.second = val;  // Store the current minimum.
            st.push_back(p); // Push the pair onto the stack.
        } else {
            // If the stack is not empty, compare the current value with the current minimum.
            pair<int, int> p;
            p.first = val;   // Store the value.
            p.second = min(val, st.back().second); // The new minimum is the smaller of the current value and the previous minimum.
            st.push_back(p); // Push the pair onto the stack.
        }
    }
    
    // Pop the top element from the stack.
    void pop() {
        st.pop_back();  // Remove the top element.
    }
    
    // Return the top element's value.
    int top() {
        return st.back().first;  // Return the value of the top element.
    }
    
    // Retrieve the minimum element from the stack.
    int getMin() {
        return st.back().second;  // Return the current minimum from the top pair.
    }
};

/*
Iterations of input/output:
Operation: MinStack()

Steps:
Initialize an empty stack.
Output: null
Operation: push(-2)

Steps:
Push (-2, -2) onto the stack (value, current minimum).
Output: null
Operation: push(0)

Steps:
Push (0, -2) onto the stack (-2 remains the minimum).
Output: null
Operation: push(-3)

Steps:
Push (-3, -3) onto the stack (-3 is the new minimum).
Output: null
Operation: getMin()

Steps:
Return the second element of the top pair, which is -3.
Output: -3
Operation: pop()

Steps:
Remove the top element (-3, -3) from the stack.
Output: null
Operation: top()

Steps:
Return the first element of the top pair, which is 0.
Output: 0
Operation: getMin()

Steps:
Return the second element of the top pair, which is -2.
Output: -2






*/