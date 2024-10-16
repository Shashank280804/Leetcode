/*
1. Initialize two pointers for both input lists.
2. Create a temporary node to serve as the head of the merged list.
3. Iterate over both lists, comparing values, and append the smaller value node to the merged list.
4. Move the pointer of the merged list and the corresponding list (list1 or list2).
5. If any nodes remain in list1 or list2, append them to the merged list.
6. Return the merged list, skipping the initial dummy node.

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Initialize pointers for both lists
        ListNode* p1 = list1;
        ListNode* p2 = list2;
        
        // Create a temporary node to build the merged list
        ListNode* temp = new ListNode(-1);
        ListNode* p3 = temp;

        // Iterate over both lists until one is fully traversed
        while (p1 != nullptr && p2 != nullptr) {
            if (p1->val < p2->val) {   // If value in list1 is smaller
                p3->next = p1;         // Append node from list1 to merged list
                p1 = p1->next;         // Move pointer forward in list1
            } else {                   // Otherwise append node from list2
                p3->next = p2;
                p2 = p2->next;         // Move pointer forward in list2
            }
            p3 = p3->next;             // Move pointer forward in the merged list
        }

        // If any nodes remain in list1, append them to the merged list
        while (p1 != nullptr) {
            p3->next = p1;
            p1 = p1->next;
        }

        // If any nodes remain in list2, append them to the merged list
        while (p2 != nullptr) {
            p3->next = p2;
            p2 = p2->next;
        }

        // Return the merged list starting from the first valid node (skipping the temp node)
        return temp->next;
    }
};
/*
list1 = [1, 2, 4], list2 = [1, 3, 4]
Iteration 1:
  p1 = 1, p2 = 1, p3 = -1
  Both values are equal, append p1 to merged list.
  Move p1 to 2, p3 to 1

Iteration 2:
  p1 = 2, p2 = 1, p3 = 1
  p2 is smaller, append p2 to merged list.
  Move p2 to 3, p3 to 1

Iteration 3:
  p1 = 2, p2 = 3, p3 = 1
  p1 is smaller, append p1 to merged list.
  Move p1 to 4, p3 to 2

Iteration 4:
  p1 = 4, p2 = 3, p3 = 2
  p2 is smaller, append p2 to merged list.
  Move p2 to 4, p3 to 3

Iteration 5:
  p1 = 4, p2 = 4, p3 = 3
  Both values are equal, append p1 to merged list.
  Move p1 to nullptr, p3 to 4

Remaining:
  p1 is nullptr, append remaining p2 (4) to merged list.

Final Output: [1, 1, 2, 3, 4, 4]

*/
