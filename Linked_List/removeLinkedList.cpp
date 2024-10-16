/*
1. Create a dummy node pointing to the head to handle edge cases.
2. Use a pointer 'curr' to traverse the list starting from the dummy node.
3. For each node, check if its next node has the target value.
4. If the next node's value matches, skip that node; otherwise, move to the next node.
5. Return the modified list starting from the original head.

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
    ListNode* removeElements(ListNode* head, int val) {
        // Create a dummy node to handle edge cases where head needs to be removed
        ListNode *temp = new ListNode(0);
        temp->next = head;

        // Initialize a pointer to traverse the list
        ListNode *curr = temp;

        // Traverse the list and remove nodes with the target value
        while (curr->next != nullptr) {
            if (curr->next->val == val) {    // If the current node's next value is equal to 'val'
                curr->next = curr->next->next; // Skip the node to remove it
            } else {
                curr = curr->next;            // Move to the next node
            }
        }

        // Return the modified list, starting from the original head
        return temp->next;
    }
};



/*
head = [1, 2, 6, 3, 4, 5, 6], val = 6
Iteration 1:
  curr = 0 (dummy node), next = 1
  No match, move curr to 1

Iteration 2:
  curr = 1, next = 2
  No match, move curr to 2

Iteration 3:
  curr = 2, next = 6
  Match found, skip node with value 6, move curr to 3

Iteration 4:
  curr = 3, next = 4
  No match, move curr to 4

Iteration 5:
  curr = 4, next = 5
  No match, move curr to 5

Iteration 6:
  curr = 5, next = 6
  Match found, skip node with value 6, move curr to nullptr (end)

Final Output: [1, 2, 3, 4, 5]
*/