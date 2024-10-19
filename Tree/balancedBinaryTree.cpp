/*
1. Define a helper function `checkHeight` to calculate the height of a node recursively:
   a. If the current node is null, return 0 (height of an empty subtree).
   b. Recursively calculate the height of the left subtree.
      - If the left subtree is unbalanced (height returned as -1), propagate -1 up the call stack.
   c. Recursively calculate the height of the right subtree.
      - If the right subtree is unbalanced, propagate -1.
   d. If the height difference between the left and right subtrees is greater than 1, return -1 to indicate imbalance.
   e. Otherwise, return the height of the current node as the maximum of the left and right heights plus 1.
2. In the `isBalanced` function, return true if `checkHeight` returns any value other than -1 (balanced), or false if -1 (unbalanced).

*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    // Helper function to check the height of the tree recursively
    int checkHeight(TreeNode* node) {
        if (node == NULL) {  // Base case: if node is null, return height 0
            return 0;
        }
        // Recursively get the height of the left subtree
        int leftHeight = checkHeight(node->left);
        if (leftHeight == -1) return -1;  // If left subtree is unbalanced, propagate -1 up
        
        // Recursively get the height of the right subtree
        int rightHeight = checkHeight(node->right);
        if (rightHeight == -1) return -1;  // If right subtree is unbalanced, propagate -1 up
        
        // If the height difference between left and right subtrees is greater than 1, return -1
        if (abs(leftHeight - rightHeight) > 1) {
            return -1;
        }
        
        // Return the height of the current node
        return 1 + max(leftHeight, rightHeight); 
    }

public:
    // Main function to determine if the tree is balanced
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;  // If -1 is returned, the tree is not balanced
    }
};



/*
Input: root = [3,9,20,null,null,15,7]
Output: true
Input: root = [3, 9, 20, null, null, 15, 7]

Step-by-Step Iteration:
1. Start at node 3 (root).
   - Calculate leftHeight for node 9 = 1 (leaf node, balanced).
   - Calculate rightHeight for node 20.
     - For node 20: leftHeight (15) = 1, rightHeight (7) = 1 (both leaf nodes, balanced).
     - maxDepth at node 20 = 2 (balanced).
   - maxDepth at node 3 = 3, and both subtrees have a height difference of 0 (balanced).

Final Output: true

*/