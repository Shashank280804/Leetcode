/*
1. Use two pointers 'slow' and 'fast' to traverse the list, with 'fast' moving twice as fast as 'slow'.
2. Reverse the first half of the list while 'slow' moves forward and 'fast' finds the middle.
3. If the list has an odd number of nodes, skip the middle node.
4. Compare the reversed first half with the second half of the list.
5. If all nodes match, return true; otherwise, return false.

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
    bool isPalindrome(ListNode* head) {
        // Initialize pointers for traversing the list
        ListNode *slow = head, *fast = head;
        ListNode *prev = nullptr, *next = head;

        // Reverse the first half of the list while finding the middle
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;  // Move 'fast' two steps ahead
            next = slow->next;        // Store the next node for 'slow'
            slow->next = prev;        // Reverse the current node of 'slow'
            prev = slow;              // Move 'prev' forward
            slow = next;              // Move 'slow' to the next node
        }

        // If the list has an odd number of nodes, skip the middle node
        if (fast != nullptr) {
            slow = slow->next;
        }

        // Compare the reversed first half with the second half
        while (slow != nullptr) {
            if (slow->val != prev->val) {
                return false;  // If any mismatch is found, it's not a palindrome
            }
            slow = slow->next;  // Move to the next node in the second half
            prev = prev->next;  // Move to the next node in the reversed first half
        }

        return true;  // If all nodes matched, the list is a palindrome
    }
};
/*
head = [1, 2, 2, 1]
Iteration 1:
  slow = 1, fast = 1, prev = nullptr
  fast moves to 2, next = 2, reverse slow (1->nullptr)
  prev moves to 1, slow moves to 2

Iteration 2:
  slow = 2, fast = 2, prev = 1
  fast moves to nullptr (end), next = 2, reverse slow (2->1)
  prev moves to 2, slow moves to 2 (second half)

Second half comparison:
  slow = 2, prev = 2
  Both values match, move slow and prev forward

  slow = 1, prev = 1
  Both values match, move slow and prev forward

Final Output: true

*/