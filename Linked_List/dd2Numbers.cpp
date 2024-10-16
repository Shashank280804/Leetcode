/*
1. Initialize a dummy head to build the result linked list.
2. Iterate while there are nodes in either l1 or l2, or there is a carry.
3. For each iteration, extract the values from l1 and l2, defaulting to 0 if a list is exhausted.
4. Calculate the sum of the two values and the carry, create a new node with the unit digit of the sum, and update the carry.
5. Link the new node to the result list and advance the pointers of l1 and l2 as necessary.


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0); // Create a dummy head for the result list
        ListNode* tail = dummyHead;             // Pointer to build the result list
        int carry = 0;                           // Variable to store carry value

        // Step 1: Iterate while either list is not empty or carry exists
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int digit1 = (l1 != nullptr) ? l1->val : 0; // Get value from l1, default to 0
            int digit2 = (l2 != nullptr) ? l2->val : 0; // Get value from l2, default to 0

            int sum = digit1 + digit2 + carry;          // Calculate sum of both digits and carry
            int digit = sum % 10;                       // Get the unit digit of the sum
            carry = sum / 10;                           // Update carry for the next iteration

            ListNode* newNode = new ListNode(digit);   // Create a new node for the resulting digit
            tail->next = newNode;                       // Link new node to the result list
            tail = tail->next;                          // Move tail pointer to the newly added node

            l1 = (l1 != nullptr) ? l1->next : nullptr; // Move to the next node in l1, if exists
            l2 = (l2 != nullptr) ? l2->next : nullptr; // Move to the next node in l2, if exists
        }

        ListNode* result = dummyHead->next; // Skip the dummy head to return the actual result list
        delete dummyHead;                   // Clean up dummy head
        return result;                      // Return the resulting linked list
    }
};





/*
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
1. **Initial Lists:** l1 = 2 -> 4 -> 3, l2 = 5 -> 6 -> 4
2. **Iteration Steps:**
   - **Step 1:** l1 = 2, l2 = 5, carry = 0
     - Sum = 2 + 5 + 0 = 7 → digit = 7, carry = 0
     - Result List: 7
   - **Step 2:** l1 = 4, l2 = 6, carry = 0
     - Sum = 4 + 6 + 0 = 10 → digit = 0, carry = 1
     - Result List: 7 -> 0
   - **Step 3:** l1 = 3, l2 = 4, carry = 1
     - Sum = 3 + 4 + 1 = 8 → digit = 8, carry = 0
     - Result List: 7 -> 0 -> 8
3. **Final Output:** 7 -> 0 -> 8 (represents the number 807)


*/