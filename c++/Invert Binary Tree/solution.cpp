/*
 * RJOrdway
 * 1st Solution, LeetCode 226: Invert Binary Tree
 * 
 * Method:
 * 
 * Concern:
 * 
 * Result:
 * 
 * Started:
 * Submitted:   
 */

 // Definition for a binary tree node.
#include <algorithm>

using std::swap;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* invertTree(TreeNode* root) {
    treeflip(root);
    return root;
}

void treeflip(TreeNode* root) {
    if (root == nullptr)
        return;
    treeflip(root->left);
    treeflip(root->right);
    swap(root->right, root->left);
}
