/*
1. Check if the list is empty, has one node, or k is zero; return head if any condition is true.
2. Initialize a pointer to traverse the list and calculate its length.
3. Calculate the effective rotations needed by reducing k to k % len.
4. If k becomes zero after the calculation, return head.
5. Traverse to the (len - k)th node to find the new tail.
6. Set the next of the new tail to NULL to break the list.
7. Connect the old tail to the old head to complete the rotation.
8. Return the new head of the rotated list.

*/
#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // Step 1: Check for edge cases where rotation is not needed
        if (head == NULL || head->next == NULL || k == 0) {
            return head; // Return head as is
        }

        // Step 2: Calculate the length of the list
        int len = 1; // Initialize length counter
        ListNode* tail = head; // Pointer to track the last node
        
        while (tail->next != NULL) { // Traverse to find the tail
            tail = tail->next; // Move to next node
            len++; // Increment length
        }

        // Step 3: Calculate effective rotations needed
        if (k > len) { // If k is larger than length
            k = k % len; // Reduce k to be within length
        }
        
        // If k is 0 after mod operation, no rotation is needed
        if (k == 0) {
            return head; // Return head as is
        }

        // Step 4: Find the new tail after k rotations
        int count = 1; // Counter for traversing
        ListNode* curr = head; // Pointer to traverse the list
        
        // Find the (len - k)th node
        while (count < len - k && curr != NULL) {
            curr = curr->next; // Move to next node
            count++; // Increment count
        }

        // Step 5: Rotate the list
        ListNode* temp = curr->next; // New head after rotation
        curr->next = NULL; // Break the link to form two separate lists
        tail->next = head; // Connect old tail to old head
        return temp; // Return the new head of the rotated list
    }
};



/*
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

1. **Initial State:** head = 1 -> 2 -> 3 -> 4 -> 5, k = 2
2. **Calculate Length:**
   - tail = 1, len = 1
   - tail = 2, len = 2
   - tail = 3, len = 3
   - tail = 4, len = 4
   - tail = 5, len = 5
3. **Calculate Effective Rotations:** 
   - k = 2 (no change since 2 < 5)
4. **Finding New Tail (len - k):**
   - Count to find (5 - 2) = 3rd node:
     - curr = 1 (count = 1)
     - curr = 2 (count = 2)
     - curr = 3 (count = 3)
5. **Rotate List:**
   - New tail found at 3
   - Break the link: 3 -> NULL
   - Connect old tail to old head: 5 -> 1
6. **Final State:** New head = 4 -> 5 -> 1 -> 2 -> 3

*/