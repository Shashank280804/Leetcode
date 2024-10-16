/*
1. Initialize two stacks to simulate the queue behavior.
2. For `push`, transfer all elements from s1 to s2, add the new element to s1, and move elements back from s2.
3. For `pop`, remove the top element from s1 (the front of the queue).
4. For `peek`, return the top element from s1 (the front of the queue).
5. For `empty`, check if s1 is empty.
*/

#include<bits/stdc++.h>
using namespace std;

class MyQueue {
private:
    stack<int> s1;  // Stack to store elements in queue order.
    stack<int> s2;  // Helper stack to assist with reordering.

public:
    // Constructor for initializing the queue.
    MyQueue() {
        // No explicit initialization needed for stacks.
    }

    // Push element to the back of the queue.
    void push(int x) {
        // Move all elements from s1 to s2 to maintain order.
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        // Push the new element to s1.
        s1.push(x);
        // Move all elements back to s1 from s2.
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    // Remove the element from the front of the queue.
    int pop() {
        int temp = s1.top();  // Get the top element from s1.
        s1.pop();             // Remove the top element.
        return temp;          // Return the removed element.
    }

    // Return the front element of the queue.
    int peek() {
        return s1.top();      // Return the element at the top of s1 (front of the queue).
    }

    // Check if the queue is empty.
    bool empty() {
        return s1.empty();    // Return true if s1 is empty, false otherwise.
    }
};

/*
Iterations of input/output:
Operation: MyQueue()

Steps:
Initialize an empty queue using two stacks.
Output: null
Operation: push(1)

Steps:
Transfer elements from s1 to s2 (none here).
Push 1 to s1 and move back elements from s2.
Output: null
Operation: push(2)

Steps:
Transfer 1 from s1 to s2.
Push 2 to s1 and move 1 back from s2 to s1.
Output: null
Operation: peek()

Steps:
Return the top element from s1, which is 1 (front of the queue).
Output: 1
Operation: pop()

Steps:
Pop the top element from s1, which is 1.
Output: 1
Operation: empty()

Steps:
Check if s1 is empty (it is not).
Output: false
*/