/*
1. Find the middle of the linked list using the slow and fast pointer technique.
2. Reverse the first half of the linked list.
3. Initialize a pointer to track the maximum pair sum.
4. Traverse both halves of the list to calculate the maximum sum of twin nodes.
5. Return the maximum sum found.
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
    int pairSum(ListNode* head) {
        ListNode* slow = head; // Initialize slow pointer to find the middle
        ListNode* fast = head; // Initialize fast pointer to find the middle

        // Step 1: Find the middle of the linked list
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next; // Move slow pointer one step
            fast = fast->next->next; // Move fast pointer two steps
        }

        // Step 2: Reverse the first half of the linked list
        ListNode* prev = head; // Previous node starts at head
        ListNode* curr = head->next; // Current node starts at head's next

        while (curr != slow) { // Continue until we reach the middle
            ListNode* temp = curr->next; // Store the next node
            curr->next = prev; // Reverse the current node's pointer
            prev = curr; // Move previous pointer to current
            curr = temp; // Move to the next node
        }

        head->next = NULL; // Terminate the first half of the reversed list

        // Step 3: Initialize a pointer to track the maximum pair sum
        int ans = 0; // Variable to store the maximum pair sum
        fast = prev; // Set fast pointer to the head of the reversed first half

        // Step 4: Calculate the maximum sum of twin nodes
        while (slow != NULL) { // Traverse the second half
            ans = max(ans, slow->val + fast->val); // Calculate pair sum and update max
            slow = slow->next; // Move slow pointer
            fast = fast->next; // Move fast pointer
        }

        // Step 5: Return the maximum sum found
        return ans; 
    }
};

/*
Initial List: 5 -> 4 -> 2 -> 1

1. **Finding the Middle:**
   - Iteration 1: slow = 4, fast = 2
   - Iteration 2: slow = 2, fast = NULL (Reached the end of the list)

   Middle found at node with value 2.

2. **Reversing the First Half:**
   - Start with prev = 5, curr = 4
   - Iteration 1: 
     - temp = 2
     - Reverse: 4 -> 5
     - Move: prev = 4, curr = 2
   - Iteration 2: 
     - temp = 1
     - Reverse: 2 -> 4
     - Move: prev = 2, curr = NULL (end of first half)

   First half reversed: 2 -> 4 -> 5.

3. **Calculating the Maximum Twin Sum:**
   - Start with fast = 2 (head of reversed first half)
   - Iteration 1: 2 + 1 = 3 (max = 3)
   - Iteration 2: 4 + 2 = 6 (max = 6)

Final Output: 6

*/