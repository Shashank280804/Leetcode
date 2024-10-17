/*
1. Initialize an empty result vector to store the traversal output.
2. Start at the root of the tree and call the helper function to traverse the tree.
3. In the helper function:
   a. If the current node is null, return.
   b. Recursively traverse the left subtree.
   c. Recursively traverse the right subtree.
   d. Add the current node's value to the result vector (after visiting both children).
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
    // This function performs postorder traversal of a binary tree.
    void postOrder(TreeNode* root, vector<int>& ans) {
        if (!root) return;  // Base case: if node is null, return
        postOrder(root->left, ans);  // Recursively visit left subtree
        postOrder(root->right, ans);  // Recursively visit right subtree
        ans.push_back(root->val);  // Add the current node's value to result after children
    }

    // Public method that initiates the postorder traversal.
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;  // Initialize result vector to store the postorder traversal
        postOrder(root, ans);  // Call the helper function to perform recursion
        return ans;  // Return the result vector
    }
};


/*
Input: root = [1,null,2,3]
Output: [3,2,1]
Input: root = [1, null, 2, 3]

Step-by-Step Iteration:
1. Start at node 1 (root).
   - Move to the right child of node 1, which is node 2.
2. Traverse the left child of node 2, which is node 3.
   - Add 3 to result. (ans = [3])
3. Add 2 (parent of node 3) to result. (ans = [3, 2])
4. Add 1 (root) to result. (ans = [3, 2, 1])

Final Output: [3, 2, 1]




*/