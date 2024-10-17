/*
1. Define a vector `v` and `v1` to store leaf values from both trees.
2. Implement a helper function `inorder` to perform inorder traversal:
   a. If the current node is NULL, return.
   b. Traverse the left subtree.
   c. If the current node is a leaf (both children are NULL), add its value to the result vector.
   d. Traverse the right subtree.
3. Call the `inorder` function for `root1` to fill vector `v`.
4. Call the `inorder` function for `root2` to fill vector `v1`.
5. Compare the sizes of `v` and `v1`. If they are not equal, return false.
6. Return true if `v` is equal to `v1`, otherwise return false.

*/
#include <vector>
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
    vector<int> v;  // Vector to store leaf values of the first tree
    vector<int> v1; // Vector to store leaf values of the second tree

    // Helper function to perform in-order traversal and collect leaf values
    void inorder(TreeNode* root, vector<int>& result) {
        if (root == nullptr)
            return;
        inorder(root->left, result);
        // Check if the node is a leaf node
        if (root->left == nullptr && root->right == nullptr) {
            result.push_back(root->val); // Add leaf value to the result
        }
        inorder(root->right, result);
    }
 
    // Function to check if two trees have the same leaf sequence
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        inorder(root1, v);  // Collect leaf values from the first tree
        inorder(root2, v1); // Collect leaf values from the second tree
        // Check if the sizes of the leaf value vectors are equal and compare them
        return v.size() == v1.size() && v == v1;
    }
};


/*
1. **Inorder Traversal of `root1`:**
   - Start at `3`, go left to `5`, go left to `6` (leaf) → v = [6]
   - Back to `5`, go right to `2`, go left to `7` (leaf) → v = [6, 7]
   - Back to `2`, go right to `4` (leaf) → v = [6, 7, 4]
   - Back to `5`, return to `3`, go right to `1`, go left (NULL), go right to `9` (leaf) → v = [6, 7, 4, 9]

2. **Inorder Traversal of `root2`:**
   - Start at `3`, go left to `5`, go left to `6` (leaf) → v1 = [6]
   - Back to `5`, go right to `1`, go left to `7` (leaf) → v1 = [6, 7]
   - Back to `1`, go right to `4` (leaf) → v1 = [6, 7, 4]
   - Back to `1`, return to `3`, go right to `2`, go left (NULL), go right to `9` (leaf) → v1 = [6, 7, 4, 9]

3. **Final Comparison:**
   - v = [6, 7, 4, 9]
   - v1 = [6, 7, 4, 9]
   - Both vectors are equal, return true.


*/