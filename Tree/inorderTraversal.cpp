/*
1. Initialize an empty result vector to store the traversal output.
2. Start at the root of the tree and call the helper function to traverse the tree.
3. In the helper function:
   a. If the current node is null, return.
   b. Recursively traverse the left subtree.
   c. Add the current node's value to the result vector.
   d. Recursively traverse the right subtree.
4. After the helper function completes, return the result vector.

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
    // This function performs inorder traversal of a binary tree.
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;  // Initialize result vector to store the inorder traversal
        inorder(root, res);  // Call the helper function to perform recursion
        return res;  // Return the result vector
    }

private:
    // Recursive helper function to traverse the tree in inorder fashion
    void inorder(TreeNode* node, vector<int>& res) {
        if (!node) {  // Base case: if node is null, return
            return;
        }
        inorder(node->left, res);  // Recursively visit left subtree
        res.push_back(node->val);  // Add the current node's value to result
        inorder(node->right, res);  // Recursively visit right subtree
    }    
};

/*
Input: root = [1, null, 2, 3]

Step-by-Step Iteration:
1. Start at node 1 (root).
   - Node 1 has no left child, so add 1 to result. (res = [1])
2. Move to the right child of node 1, which is node 2.
   - Traverse the left subtree of node 2.
   - Add 3 (left child of node 2) to result. (res = [1, 3])
3. Add 2 to the result. (res = [1, 3, 2])

Final Output: [1, 3, 2]

*/