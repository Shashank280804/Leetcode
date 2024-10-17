/*
1. Check if root1 is null; if so, return root2 (there's nothing to merge from root1).
2. Check if root2 is null; if so, return root1 (there's nothing to merge from root2).
3. Create a new node with the value equal to the sum of root1 and root2 values.
4. Recursively call mergeTrees for the left children of root1 and root2, assigning the result to the left child of the merged node.
5. Recursively call mergeTrees for the right children of root1 and root2, assigning the result to the right child of the merged node.
6. Return the merged node.

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
    // Function to merge two binary trees
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // If root1 is null, return root2
        if (root1 == NULL) return root2;
        // If root2 is null, return root1
        if (root2 == NULL) return root1;
        // Create a new node by summing values of root1 and root2
        TreeNode* merged = new TreeNode(root1->val + root2->val);
        // Recursively merge the left children
        merged->left = mergeTrees(root1->left, root2->left);
        // Recursively merge the right children
        merged->right = mergeTrees(root1->right, root2->right);
        
        return merged; 
    }
};

/*
Input: root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]

Step-by-Step Iteration:
1. Start merging at root1 (1) and root2 (2):
   - Create a new node with value 1 + 2 = 3.
2. Merge left children:
   - root1->left (3) and root2->left (1):
     - Create a new node with value 3 + 1 = 4.
   - Merge their left children:
     - root1->left->left (5) and root2->left->left (null):
       - Create a new node with value 5.
     - No right children to merge (both null).
3. Merge right children:
   - root1->right (2) and root2->right (3):
     - Create a new node with value 2 + 3 = 5.
   - Merge their left children (both null).
   - Merge their right children:
     - root1->right->right (null) and root2->right->right (7):
       - Create a new node with value 7.

Final Merged Tree:
Output: [3,4,5,5,4,null,7]

*/