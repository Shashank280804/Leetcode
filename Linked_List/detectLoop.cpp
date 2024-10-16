/*
1. Initialize two pointers, fast and slow, both starting at the head of the linked list.
2. Traverse the list, moving the fast pointer two steps and the slow pointer one step at a time.
3. If the fast pointer meets the slow pointer, a cycle is present in the list.
4. If the fast pointer reaches the end of the list (NULL), then no cycle exists.
5. Return true if a cycle is found, otherwise return false.

*/

#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head; // Initialize fast pointer to head
        ListNode *slow = head; // Initialize slow pointer to head
        
        // Step 1: Traverse the list until the fast pointer reaches the end or NULL
        while (fast != NULL && fast->next != NULL) { 
            fast = fast->next->next; // Move fast pointer two steps ahead
            slow = slow->next; // Move slow pointer one step ahead
            
            // Step 2: If fast meets slow, there is a cycle
            if (fast == slow) { 
                return true; // Cycle detected
            }
        }
        return false; // Step 3: If fast reaches NULL, there is no cycle
    }
};




/*
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
1. **Initial State:** head = 3 -> 2 -> 0 -> -4 (cycle at node with value 2)
2. **Iteration Steps:**
   - **Step 1:** 
     - slow = 3, fast = 3
     - Move slow to 2, fast to 0 (slow moves one step, fast moves two steps)
   - **Step 2:**
     - slow = 2, fast = 0
     - Move slow to 0, fast to NULL (fast reaches the end)
3. **Conclusion:** Since fast reached NULL, there is no cycle in the linked list.

*/