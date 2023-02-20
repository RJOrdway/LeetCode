/*
 * RJOrdway
 * 1st Solution, LeetCode 783: Minimum Distance Between BST Nodes

 * 
 * Method: Use a set, store values (that don't repeat), iterate over set to find least difference
 * 
 * Concern: Duplicates work, uses more memory in set than might be needed
 * 
 * Result:
 * 
 * Started:     02/17/23
 * Submitted:   02/17/23
 */

#include <set>

using std::set;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int minDiffInBST(TreeNode* root) {
    set<int> nums;
    treedigger(root, nums);
    if (nums.size() == 1) {
        return 0;
    }
    auto it = nums.begin();
    int prev = *it;
    it++;
    int current = *it;
    int leastDiff = current - prev;
    it++;
    for (it; it != nums.end(); it++) {
        prev = current;
        current = *it;
        leastDiff = leastDiff*(leastDiff<=(current-prev)) + (current-prev)*(leastDiff>(current-prev));
    }

    return leastDiff;
}

void treedigger(TreeNode* root, set<int>& nums) {
    nums.insert(root->val);
    if (root->left != nullptr)
        treedigger(root->left, nums);
    if (root->right != nullptr)
        treedigger(root->right, nums);
}

int main() {



    return 1;
}