/*
1. Initialize a variable `res` to store the maximum diameter.
2. Call a helper function to calculate the diameter recursively:
   a. If the current node is null, return 0.
   b. Recursively calculate the depth of the left subtree.
   c. Recursively calculate the depth of the right subtree.
   d. Update the diameter `res` by comparing the current diameter (left depth + right depth) with the previous maximum.
   e. Return the depth of the current node as the maximum of the left and right depths plus 1 (for the current node).
3. Return the maximum diameter after the recursion finishes.

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
    // Public method to calculate the diameter of the binary tree
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;  // Initialize result to store the maximum diameter
        diameter(root, res);  // Call the helper function
        return res;  // Return the calculated maximum diameter
    }

private:
    // Helper function to calculate the diameter recursively
    int diameter(TreeNode* curr, int& res) {
        if (!curr) return 0;  // Base case: if node is null, return 0
        
        // Recursively calculate the depth of the left and right subtrees
        int left = diameter(curr->left, res);
        int right = diameter(curr->right, res);
        
        // Update the maximum diameter by comparing current diameter (left + right) with previous maximum
        res = std::max(res, left + right);
        
        // Return the depth of the current node as max of left and right depth plus 1 (for the current node)
        return std::max(left, right) + 1;
    }
};

/*
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

Input: root = [1, 2, 3, 4, 5]

Step-by-Step Iteration:
1. Start at node 1 (root).
   - Calculate leftDepth for node 2.
     - For node 2: leftDepth (node 4) = 1, rightDepth (node 5) = 1.
     - maxDepth at node 2 = 2, and diameter through node 2 = 2.
   - Calculate rightDepth for node 3 = 1.
   - maxDepth at node 1 = 3, and diameter through node 1 = 3.

Final Output: 3

*/