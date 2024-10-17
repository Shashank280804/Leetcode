/*
1. Check if the current node (root) is null; if so, return (base case).
2. If the node's value is within the range [low, high], add it to the sum (ans).
3. Recursively call the solve function for the left child and the right child:
   - This ensures all nodes are checked for the given range.
4. Return the accumulated sum (ans) from the rangeSumBST function.

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
    // Helper function to compute the sum of nodes within the range [low, high]
    void solve(TreeNode* root, int low, int high, int &ans) {
        if(root == NULL) {
            return; // Base case: If the node is null, return
        }

        // Check if the current node's value is within the range [low, high]
        if(root->val >= low && root->val <= high) {
            ans += root->val; // Add the value to the sum
        }

        // Recursively check the left and right subtrees
        solve(root->left, low, high, ans);
        solve(root->right, low, high, ans);
    }

    // Main function to initiate the range sum calculation
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0; // Initialize the sum
        solve(root, low, high, ans); // Call the helper function
        return ans; // Return the final sum
    }
};

/*
Input: root = [10,5,15,3,7,null,18], low = 7, high = 15

Step-by-Step Iteration:
1. Start at root (10):
   - 10 is within the range [7, 15]; add 10 to ans (ans = 10).
2. Move to left child (5):
   - 5 is not in the range; do not add to ans (ans = 10).
   - Check left child (3):
     - 3 is not in the range; do not add to ans (ans = 10).
   - Check right child (7):
     - 7 is in the range; add 7 to ans (ans = 17).
3. Backtrack to root (10) and check right child (15):
   - 15 is in the range; add 15 to ans (ans = 32).
   - Check left child (null): do nothing.
   - Check right child (18):
     - 18 is not in the range; do not add to ans (ans = 32).

Output: 32

*/