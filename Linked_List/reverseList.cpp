/*
1. Check if the head is null or has only one node, return it directly.
2. Initialize 'prev' as null, 'curr' as head, and start traversal.
3. For each node, store the next node, reverse the current node's pointer, and move 'prev' and 'curr' one step ahead.
4. Continue until 'curr' becomes null, indicating the end of the list.
5. Return 'prev' as the new head of the reversed list.

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
    ListNode* reverseList(ListNode* head) {
        // If the list is empty or has only one node, return the head (no need to reverse)
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        // Initialize pointers: 'curr' to traverse the list, 'prev' to reverse links, and 'next' for temporary storage
        ListNode *curr, *prev, *next;
        curr = head;
        prev = nullptr;

        // Loop through the list and reverse the links
        while (curr != nullptr) {
            next = curr->next;  // Save the next node
            curr->next = prev;  // Reverse the current node's next pointer
            prev = curr;        // Move 'prev' to current node
            curr = next;        // Move 'curr' to the next node in the original list
        }
        
        // Return the new head of the reversed list
        return prev;
    }
};

/*
head = [1, 2, 3, 4, 5]
Iteration 1: 
  curr = 1, prev = nullptr
  next = 2, curr->next = prev (nullptr)
  Move prev to 1, curr to 2

Iteration 2:
  curr = 2, prev = 1
  next = 3, curr->next = prev (1)
  Move prev to 2, curr to 3

Iteration 3:
  curr = 3, prev = 2
  next = 4, curr->next = prev (2)
  Move prev to 3, curr to 4

Iteration 4:
  curr = 4, prev = 3
  next = 5, curr->next = prev (3)
  Move prev to 4, curr to 5

Iteration 5:
  curr = 5, prev = 4
  next = nullptr, curr->next = prev (4)
  Move prev to 5, curr to nullptr

Final Output: [5, 4, 3, 2, 1]

*/