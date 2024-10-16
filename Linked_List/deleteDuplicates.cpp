/*
1. Initialize a pointer 'temp' to traverse the list.
2. Iterate through the list while the current node and its next node exist.
3. If the current node's value equals the next node's value, skip the next node by adjusting the pointer.
4. Otherwise, move to the next node.
5. Return the modified list after removing duplicates.

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
    ListNode* deleteDuplicates(ListNode* head) {
        // Initialize pointer to traverse the list
        ListNode* temp = head;

        // Traverse the list until reaching the end
        while (temp != nullptr && temp->next != nullptr) {
            // If the current node value is equal to the next node value
            if (temp->val == temp->next->val) {
                // Skip the next node by adjusting the pointers
                temp->next = temp->next->next;
            } else {
                // Move to the next node if values are not equal
                temp = temp->next;
            }
        }

        // Return the modified list without duplicates
        return head;
    }
};

/*
Iteration 1:
  temp = 1, next = 1
  Duplicate found, skip the second '1', move temp to 2

Iteration 2:
  temp = 2, next = nullptr
  No more nodes to compare, end loop

Final Output: [1, 2]


*/