/*
1. Check if the current node (root) is null; if so, return false (no path).
2. Check if the current node is a leaf (both left and right children are null):
   - If it is, compare the node's value with the target sum; return true if they match, false otherwise.
3. Recursively call hasPathSum for the left and right children of the current node:
   - Subtract the current node's value from the target sum for the next level.
4. Return true if either the left or right subtree has a path that matches the target sum.

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
    // Function to check if there's a root-to-leaf path with the target sum
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false; // If the node is null, return false
        if (!root->left && !root->right) // If it's a leaf node
            return root->val == sum; // Check if the leaf value equals the remaining sum
        // Recursively check left and right subtrees with the reduced sum
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};

/*
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22

Step-by-Step Iteration:
1. Start at root (5), targetSum = 22:
   - Check left child (4), new targetSum = 22 - 5 = 17.
2. Move to node (4):
   - Check left child (11), new targetSum = 17 - 4 = 13.
3. Move to node (11):
   - Check left child (7), new targetSum = 13 - 11 = 2.
4. Move to node (7):
   - Leaf node reached, check if 7 equals 2; it's false.
5. Backtrack to node (11) and check right child (2), new targetSum = 13 - 11 = 2.
6. Move to node (2):
   - Leaf node reached, check if 2 equals 2; it's true.
7. Path found: 5 -> 4 -> 11 -> 2, which sums to 22.

Output: true

*/