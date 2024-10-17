/*
1. Initialize an empty result vector to store the traversal output.
2. Start at the root of the tree and call the helper function to traverse the tree.
3. In the helper function:
   a. If the current node is null, return.
   b. Add the current node's value to the result vector.
   c. Recursively traverse the left subtree.
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
    // This function performs preorder traversal of a binary tree.
    void preOrder(TreeNode* root, vector<int>& ans) {
        if (root == NULL) return;  // Base case: if node is null, return
        ans.push_back(root->val);  // Add the current node's value to result
        preOrder(root->left, ans);  // Recursively visit left subtree
        preOrder(root->right, ans);  // Recursively visit right subtree
    }
    
    // Public method that initiates the preorder traversal.
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;  // Initialize result vector to store the preorder traversal
        preOrder(root, ans);  // Call the helper function to perform recursion
        return ans;  // Return the result vector
    }
};


/*
Input: root = [1,null,2,3]
Output: [1,2,3]
Input: root = [1, null, 2, 3]

Step-by-Step Iteration:
1. Start at node 1 (root).
   - Add 1 to result. (ans = [1])
2. Move to the right child of node 1, which is node 2.
   - Add 2 to result. (ans = [1, 2])
3. Traverse the left child of node 2, which is node 3.
   - Add 3 to result. (ans = [1, 2, 3])

Final Output: [1, 2, 3]


*/