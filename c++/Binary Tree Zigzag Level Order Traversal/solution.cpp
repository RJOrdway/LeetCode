/*
 * RJOrdway
 * 1st Solution, LeetCode 103: Binary Tree Zigzag Level Order Traversal
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
#include <vector>

using std::vector;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<TreeNode*>> zig;
    vector<vector<int>> values;
    zig.push_back(vector<TreeNode*>{root});
    bool leftRight = false;

    for (int i = 0; i < zig.size(); i++) {
        vector<TreeNode*> nextZag;
        vector<int> nextValues;
        vector<TreeNode*>
        for (int j = 0; j < zig[i].size(); j++) {
            nextValues.push_back(zig[i][j]->val);

        }
    }

}
