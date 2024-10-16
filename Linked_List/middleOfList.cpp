/*
1. Initialize two pointers, slowPointer and fastPointer, both starting at the head.
2. Move slowPointer by one step and fastPointer by two steps in each iteration.
3. Continue until fastPointer reaches the end of the list.
4. When fastPointer reaches the end, slowPointer will point to the middle node.
5. Return the middle node.

*/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // Initialize two pointers, slowPointer and fastPointer
        ListNode* slowPointer = head;
        ListNode* fastPointer = head;

        // Move slowPointer one step and fastPointer two steps until fastPointer reaches the end
        while (fastPointer != nullptr && fastPointer->next != nullptr) {
            slowPointer = slowPointer->next;       // Move slow pointer by one node
            fastPointer = fastPointer->next->next; // Move fast pointer by two nodes
        }

        // When fastPointer reaches the end, slowPointer will be at the middle
        return slowPointer;
    }
};
/*
head = [1, 2, 3, 4, 5]
Iteration 1:
  slowPointer = 1, fastPointer = 1
  slowPointer moves to 2, fastPointer moves to 3

Iteration 2:
  slowPointer = 2, fastPointer = 3
  slowPointer moves to 3, fastPointer moves to 5

Iteration 3:
  slowPointer = 3, fastPointer = 5
  fastPointer reaches the end, slowPointer is at 3

Final Output: [3, 4, 5]


*/