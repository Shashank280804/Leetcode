/*
1. Initialize a queue and a variable to track the top element.
2. For `push`, add the element to the queue and update the top element.
3. For `pop`, move all elements except the last to the back, then pop the last one.
4. For `top`, return the value of the top element variable.
5. For `empty`, check if the queue is empty.

*/

#include<bits/stdc++.h>
using namespace std;

class MyStack {
    queue<int> q;  // Initialize a queue to implement stack behavior.
    int topele;    // Variable to store the top element of the stack.
    
public:
    MyStack() {
        // Constructor doesn't need to initialize anything explicitly.
    }
    
    // Push an element onto the stack.
    void push(int x) {
        q.push(x);  // Add the element to the queue.
        topele = x; // Update the top element.
    }
    
    // Pop the top element from the stack.
    int pop() {
        int size = q.size();  // Get the size of the queue.
        // Move all elements except the last one to the back.
        while(size > 1) {
            this->push(q.front());  // Push the front element to simulate queue behavior.
            q.pop();                // Remove the front element.
            size--;
        }
        // The last element is the one to pop (stack behavior).
        int x = q.front();
        q.pop();                    // Remove the last element from the queue.
        return x;                   // Return the popped element.
    }
    
    // Return the top element of the stack.
    int top() {
        return this->topele;         // Return the value stored in `topele`.
    }
    
    // Check if the stack is empty.
    bool empty() {
        return q.empty();            // Return whether the queue is empty.
    }
};

/*
Iterations of input/output:
Operation: MyStack()

Steps:
Initialize the stack using a queue.
Output: null (stack is initialized)
Operation: push(1)

Steps:
Push 1 to the queue.
Update top element to 1.
Output: null
Operation: push(2)

Steps:
Push 2 to the queue.
Update top element to 2.
Output: null
Operation: top()

Steps:
Return the top element, which is 2.
Output: 2
Operation: pop()

Steps:
Pop 2 (the last element pushed) after moving other elements to the back.
Output: 2
Operation: empty()

Steps:
Check if the queue is empty (it is not).
Output: false
*/