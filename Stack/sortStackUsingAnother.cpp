/*
1. Initialize a temporary stack to store sorted elements.
2. Pop elements from the original stack one by one.
3. For each element, move larger elements from the temporary stack back to the original stack.
4. Push the current element to the temporary stack in sorted order.
5. Once all elements are processed, transfer sorted elements back to the original stack.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to sort a stack using another stack.
    void sortStack(stack<int>& s) {
        stack<int> tempStack;  // Temporary stack to hold sorted elements.
        
        // Process each element from the original stack.
        while(!s.empty()) {
            int current = s.top();  // Get the top element of the original stack.
            s.pop();                // Remove the top element from the original stack.

            // Move elements from tempStack back to the original stack if they are larger than the current element.
            while(!tempStack.empty() && tempStack.top() > current) {
                s.push(tempStack.top());  // Push back larger elements to the original stack.
                tempStack.pop();          // Remove the element from tempStack.
            }

            // Place the current element in its correct position in tempStack.
            tempStack.push(current);
        }

        // Transfer the sorted elements back from tempStack to the original stack.
        while(!tempStack.empty()) {
            s.push(tempStack.top());  // Push sorted elements back to the original stack.
            tempStack.pop();          // Remove from tempStack.
        }
    }
};

/*
Iterations of input/output:
Input Stack: s = [3, 1, 4, 2]
Steps:
Pop 2 and push to tempStack (tempStack = [2]).
Pop 4, move 2 back to s, push 4 to tempStack (tempStack = [4]).
Pop 2 and push to tempStack (tempStack = [4, 2]).
Pop 1, move all elements back to s, push 1 to tempStack (tempStack = [1]).
Continue this process until all elements are sorted and moved back to s.
Output Stack: s = [1, 2, 3, 4]
*/