/*
1. Check if the list is empty or has only one node; if so, return the head as it is already sorted.
2. Define a merge function to combine two sorted linked lists into one sorted linked list.
3. Define a findMiddle function to locate the middle node of the linked list.
4. Split the list into two halves at the middle node.
5. Recursively sort both halves of the list.
6. Merge the two sorted halves using the merge function.
7. Return the head of the newly sorted linked list.

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
    ListNode* sortList(ListNode* head) {
        // Step 1: Base case for recursion
        if (!head || !head->next) {
            return head; // If the list is empty or has only one element, it's already sorted
        }

        // Step 2: Lambda function to merge two sorted lists
        auto merge = [](ListNode* left, ListNode* right) -> ListNode* {
            ListNode dummy(0); // Dummy node to help build the merged list
            ListNode* curr = &dummy; // Pointer to track the end of the merged list

            // Step 3: Merge the two lists while both have nodes
            while (left && right) {
                if (left->val <= right->val) { // Compare values
                    curr->next = left; // Append left node
                    left = left->next; // Move to the next node in left list
                } else {
                    curr->next = right; // Append right node
                    right = right->next; // Move to the next node in right list
                }
                curr = curr->next; // Move the current pointer
            }

            // Step 4: Append any remaining nodes from either list
            curr->next = left ? left : right;

            return dummy.next; // Return the merged list starting from the first real node
        };

        // Step 5: Lambda function to find the middle node of the list
        auto findMiddle = [](ListNode* node) -> ListNode* {
            ListNode* slow = node; // Slow pointer to find the middle
            ListNode* fast = node->next; // Fast pointer

            // Move slow one step and fast two steps to find the middle
            while (fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
            }

            return slow; // Return the middle node
        };

        ListNode* mid = findMiddle(head); // Find the middle of the list
        ListNode* rightHead = mid->next; // Split the list into two halves
        mid->next = nullptr; // Terminate the left half

        // Step 6: Recursively sort the two halves
        ListNode* sortedLeft = sortList(head);
        ListNode* sortedRight = sortList(rightHead);

        // Step 7: Merge the sorted halves and return the result
        return merge(sortedLeft, sortedRight);
    }
};





/*
Input: head = [4,2,1,3]
Output: [1,2,3,4]
1. **Initial State:** head = 4 -> 2 -> 1 -> 3
2. **Finding Middle:**
   - slow = 4, fast = 2
   - slow = 2, fast = 1
   - slow = 1, fast = NULL
   - Mid found: 1
3. **Splitting Lists:**
   - Left: 4 -> 2 -> 1
   - Right: 3
4. **Sorting Left Half (4 -> 2 -> 1):**
   - Finding middle of left: Mid found: 2
   - Splitting into Left: 4, Right: 1
5. **Sorting Right Half (1):** Already sorted, return 1.
6. **Merging (4 -> 2) and (1):**
   - Merged result: 1 -> 2 -> 4
7. **Sorting Right Half (3):** Already sorted, return 3.
8. **Final Merge (1 -> 2 -> 4) and (3):**
   - Merged result: 1 -> 2 -> 3 -> 4

*/