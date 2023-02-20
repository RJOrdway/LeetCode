/*
 * RJOrdway
 * 1st Solution, LeetCode 104: Maximum Depth of Binary Tree
 * 
 * Method: recursion
 * 
 * Concern: 
 * 
 * Result: 
 *      Runtime 16 ms
 *      Beats 21.87%
 *      Memory 18.9 MB
 *      Beats 64.6%
 * 
 * Started:     02/16/23
 * Submitted:   02/16/23
 */

using namespace std;

 //Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

int maxDepth(TreeNode* root) {
    int l = 1;
    int r = 1;
    if (root == nullptr)
        return 0;
    if (root->left != nullptr)
        l = checkdepth(root->left, l+1);
    if (root->right != nullptr)
        r = checkdepth(root->right, r+1);
    return l*(l>=r) + r*(r>l);
};

int checkdepth(TreeNode* root, int val) {
    int l = val;
    int r = val;
    if (root->left != nullptr)
        l = checkdepth(root->left, l+1);
    if (root->right != nullptr)
        r = checkdepth(root->right, r+1);
    return l*(l>=r) + r*(r>l);
}