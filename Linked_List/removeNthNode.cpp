/*
1. Create a dummy node to simplify edge cases.
2. Move a pointer `first` n+1 steps ahead from the dummy node.
3. Move both pointers `first` and `second` until `first` reaches the end of the list.
4. The `second` pointer will now point to the node before the one to be removed.
5. Bypass the nth node from the end by linking `second` to its next node's next.
a
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0); // Create a dummy node
        dummy->next = head;                 // Link dummy to the head of the list
        ListNode* first = dummy;            // Pointer to traverse the list
        ListNode* second = dummy;           // Pointer to find the node to remove

        // Step 1: Move first pointer n+1 steps ahead
        for (int i = 0; i <= n; ++i) {
            first = first->next;            // Move first pointer
        }

        // Step 2: Move both pointers until the first pointer reaches the end
        while (first != nullptr) {
            first = first->next;            // Move first pointer
            second = second->next;          // Move second pointer
        }

        // Step 3: Remove the nth node from the end
        ListNode* temp = second->next;     // Node to be removed
        second->next = second->next->next; // Bypass the node
        delete temp;                       // Free the memory of the removed node

        return dummy->next;                // Return the new head of the list
    }
};



/*
1. **Initial List:** 1 -> 2 -> 3 -> 4 -> 5, n = 2
2. **Moving the First Pointer:**
   - Step 1: Move first pointer ahead by n+1 (3 steps)
     - Iteration 1: first points to 1
     - Iteration 2: first points to 2
     - Iteration 3: first points to 3
     - Iteration 4: first points to 4 (now at the end)
3. **Moving Both Pointers:**
   - Iteration 1: first points to 5, second points to 1
   - Iteration 2: first points to nullptr, second points to 2
4. **Removing the Nth Node:**
   - Second points to 2, its next is 3, remove 4
   - New list: 1 -> 2 -> 3 -> 5

*/