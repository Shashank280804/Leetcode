/*
1. If the current node is null, return 0 (base case).
2. Recursively calculate the depth of the left subtree.
3. Recursively calculate the depth of the right subtree.
4. The maximum depth of the tree at the current node is the greater of the two depths (left or right) plus 1 (to account for the current node).
5. Return the calculated maximum depth.

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
    // This function calculates the maximum depth of a binary tree.
    int maxDepth(TreeNode* root) {
        if (root == NULL)  // Base case: if node is null, return 0
            return 0;
        // Recursively calculate the depth of the left and right subtrees
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        // Return the greater depth + 1 (for the current node)
        int totalDepth = max(leftDepth, rightDepth) + 1;
        return totalDepth;
    }
};





/*
Input: root = [3,9,20,null,null,15,7]
Output: 3
Input: root = [3, 9, 20, null, null, 15, 7]

Step-by-Step Iteration:
1. Start at node 3 (root).
   - Calculate leftDepth for node 9 (leaf node) = 1.
   - Calculate rightDepth for node 20.
     - For node 20: leftDepth (15) = 1, rightDepth (7) = 1.
     - maxDepth at node 20 = 2.
2. maxDepth at node 3 = max(1, 2) + 1 = 3.

Final Output: 3

*/