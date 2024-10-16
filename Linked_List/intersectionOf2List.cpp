/*
1. Iterate through each node in list A.
2. For each node in list A, iterate through all nodes in list B.
3. Check if the current node of list A is the same as the current node of list B (intersection).
4. If an intersection is found, return that node.
5. If no intersection is found after traversing both lists, return NULL.

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Iterate through each node in list A
        while (headA != NULL) {
            ListNode *temp = headB; // Pointer to traverse list B
            
            // Iterate through list B
            while (temp != NULL) {
                // Check if the nodes point to the same address (intersection)
                if (headA == temp) {
                    return headA; // Return the intersection node
                }
                temp = temp->next; // Move to the next node in list B
            }
            headA = headA->next; // Move to the next node in list A
        }
        return NULL; // No intersection found
    }
};


/*
intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
List A: 4 -> 1 -> 8 -> 4 -> 5
List B: 5 -> 6 -> 1 -> 8 -> 4 -> 5
Intersection starts at node with value 8.

Iteration 1:
  headA = 4
  Iterate through list B:
    - temp = 5 (no match)
    - temp = 6 (no match)
    - temp = 1 (no match)
    - temp = 8 (no match)
    - No intersection found, move headA to 1

Iteration 2:
  headA = 1
  Iterate through list B:
    - temp = 5 (no match)
    - temp = 6 (no match)
    - temp = 1 (no match)
    - temp = 8 (no match)
    - No intersection found, move headA to 8

Iteration 3:
  headA = 8
  Iterate through list B:
    - temp = 5 (no match)
    - temp = 6 (no match)
    - temp = 1 (no match)
    - temp = 8 (match found, intersection)
    
Final Output: Intersected at '8'

*/