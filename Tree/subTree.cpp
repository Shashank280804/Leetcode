/*
1. If the subRoot is null, return true (an empty tree is always a subtree).
2. If the root is null but subRoot is not, return false (subRoot cannot be a subtree).
3. Check if the root and subRoot are identical using the isidentical helper function.
4. If the trees are identical, return true.
5. Recursively check if subRoot is a subtree of root's left or right child.
6. The isidentical function compares two trees:
   - If both nodes are null, return true.
   - If one node is null and the other is not, return false.
   - If the values of both nodes are not equal, return false.
   - Recursively check the left and right subtrees for equality.

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
    // Function to check if subRoot is a subtree of root
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // If subRoot is null, return true (an empty tree is always a subtree)
        if(subRoot == NULL)
            return true;
        // If root is null but subRoot is not, return false
        if(root == NULL)
            return false;
        // If both trees are identical, return true
        if(isidentical(root, subRoot))
            return true;
        // Otherwise, recursively check the left and right subtrees
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    // Helper function to check if two trees are identical
    bool isidentical(TreeNode* a, TreeNode* b) {
        // If both nodes are null, return true (both trees are empty)
        if(a == NULL && b == NULL)
            return true;
        // If one of the nodes is null, return false (trees are not identical)
        if(a == NULL || b == NULL)
            return false;
        // If values of the nodes do not match, return false
        if(a->val != b->val)
            return false;
        // Recursively check if the left and right subtrees are identical
        return isidentical(a->left, b->left) && isidentical(a->right, b->right);
    }
};



/*
Input: root = [3,4,5,1,2], subRoot = [4,1,2]

Step-by-Step Iteration:
1. Start at root (3) and subRoot (4).
   - Root and subRoot are not identical (values 3 and 4 do not match).
   - Check root's left subtree: root->left (4).
2. Compare root->left (4) and subRoot (4).
   - Both nodes are non-null and have the same value (4).
   - Check left subtrees: root->left->left (1) and subRoot->left (1).
     - Both nodes are non-null and have the same value (1), and both have null children.
     - Return true for left subtrees.
   - Check right subtrees: root->left->right (2) and subRoot->right (2).
     - Both nodes are non-null and have the same value (2), and both have null children.
     - Return true for right subtrees.
3. Since both left and right subtrees are identical, return true.

Final Output: true

*/