/*
1. If the current node is null, return null (base case).
2. Swap the left and right children of the current node.
3. Recursively invert the left subtree.
4. Recursively invert the right subtree.
5. After all nodes are inverted, return the root of the tree.

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
    // This function inverts a binary tree by swapping the left and right child nodes recursively.
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {  // Base case: if the node is null, return null
            return nullptr;
        }
        
        // Swap the left and right child nodes
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        // Recursively invert the left and right subtrees
        invertTree(root->left);
        invertTree(root->right);
        
        return root;  // Return the root after inversion
    }
};

/*
Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

Input: root = [4, 2, 7, 1, 3, 6, 9]

Step-by-Step Iteration:
1. Start at node 4 (root).
   - Swap the left child (2) and right child (7).
2. Move to node 7.
   - Swap its left child (6) and right child (9).
   - (Result so far: 4 -> [7, 2], 7 -> [9, 6])
3. Move to node 2.
   - Swap its left child (1) and right child (3).
   - (Result so far: 4 -> [7, 2], 7 -> [9, 6], 2 -> [3, 1])

Final Output: [4, 7, 2, 9, 6, 3, 1]

*/