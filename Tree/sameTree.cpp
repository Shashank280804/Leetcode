/*
1. If both nodes `p` and `q` are null, return true (both subtrees are empty).
2. If one node is null while the other is not, return false (one subtree is empty, the other is not).
3. If the values of the current nodes `p` and `q` are not equal, return false (values are different).
4. Recursively check if the left subtrees of both nodes are identical and if the right subtrees are identical.
5. Return true only if both left and right subtrees are identical.

*/
#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Function to check if two trees are identical
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Case when both nodes are null (empty subtrees), return true
        if (p == NULL && q == NULL) {
            return true;
        }
        // Case when only one node is null (one subtree empty, other not), return false
        else if (p == NULL || q == NULL) {
            return false;
        }
        // Case when values of the current nodes are not the same, return false
        else if (p->val != q->val) {
            return false;
        }
        // Recursively check if left and right subtrees are identical
        else {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    }
};


/*
Input: p = [1,2,3], q = [1,2,3]
Output: true


Step-by-Step Iteration:
1. Start at root nodes p (1) and q (1).
   - Both nodes are non-null and have the same value (1).
   - Check left subtrees: p->left (2) and q->left (2).
     - Both nodes are non-null and have the same value (2), and both have null children.
     - Return true for left subtrees.
   - Check right subtrees: p->right (3) and q->right (3).
     - Both nodes are non-null and have the same value (3), and both have null children.
     - Return true for right subtrees.
2. Since both left and right subtrees are identical, return true.

Final Output: true


*/