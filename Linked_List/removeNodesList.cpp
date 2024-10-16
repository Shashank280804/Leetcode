/*
1. Reverse the linked list.
2. Initialize a pointer to track the maximum value seen so far.
3. Traverse the reversed list and for each node, if its value is greater than or equal to the maximum value, keep it and update the maximum.
4. Link the kept nodes together.
5. Terminate the list and reverse it back to the original order before returning it.

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
    // Function to reverse the linked list
    ListNode* rev(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = head;
        
        // Reverse the list
        while (next != NULL) {
            curr = next;      // Store current node
            next = curr->next; // Move to the next node
            curr->next = prev; // Reverse the link
            prev = curr;      // Move prev pointer to current node
        }
        return curr; // New head of the reversed list
    }
     
public:
    ListNode* removeNodes(ListNode* head) {
        ios_base::sync_with_stdio(0); // Optimize input/output speed
        
        // If the list is empty or has only one node, return it as is
        if (head == NULL || head->next == NULL) return head;

        head = rev(head); // Reverse the linked list
        ListNode* prev = NULL;
        ListNode* head2 = head; // Store the head of the reversed list
        int mx = 0; // Variable to keep track of the maximum value
        
        // Iterate through the reversed list
        while (head != NULL) {
            // If the current node's value is greater than or equal to mx
            if (head->val >= mx) {
                // Link the previous node to the current node
                if (prev != head) {
                    prev->next = head; 
                    prev = head; // Move prev to current
                }
                mx = head->val; // Update mx to current node's value
            }
            head = head->next; // Move to the next node
        }
        
        prev->next = NULL; // Terminate the list at the last valid node
        return rev(head2); // Reverse the modified list back to original order
    }
};


/*
head = [5, 2, 13, 3, 8]
Initial List: 5 -> 2 -> 13 -> 3 -> 8

1. **Reverse the List:**
   - Iteration 1: prev = NULL, curr = 5, next = 2 → 2 -> 5
   - Iteration 2: prev = 5, curr = 2, next = 13 → 13 -> 2 -> 5
   - Iteration 3: prev = 2, curr = 13, next = 3 → 3 -> 13 -> 2 -> 5
   - Iteration 4: prev = 13, curr = 3, next = 8 → 8 -> 3 -> 13 -> 2 -> 5
   - Iteration 5: prev = 3, curr = 8, next = NULL → NULL -> 8 -> 3 -> 13 -> 2 -> 5
   - Reversed List: 8 -> 3 -> 13 -> 2 -> 5

2. **Remove Nodes:**
   - Start with mx = 0.
   - Node 8: 8 >= 0 (keep it), mx = 8.
   - Node 3: 3 < 8 (remove it).
   - Node 13: 13 >= 8 (keep it), mx = 13.
   - Node 2: 2 < 13 (remove it).
   - Node 5: 5 < 13 (remove it).
   - Kept Nodes: 8 -> 13.

3. **Reverse the Modified List Back:**
   - Reversed List: 13 -> 8.

Final Output: [13, 8]

*/