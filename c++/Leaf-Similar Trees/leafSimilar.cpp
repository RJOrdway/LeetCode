/*
 * RJOrdway
 * 1st Solution, LeetCode 872: Leaf-Similar Trees
 * 
 * Method:  store leaf sequence in vector, compare
 * 
 * Concern:
 * 
 * Result:
 * 
 * Started:     12/8/22
 * Submitted:   
 */

#include <iostream>
#include <vector>
#include <queue>

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

// Helper function to build test nodes, built by me
// Cannot handle empty vectors, since problem constraint specifies each tree will have
// [1, 200] nodes per tree
TreeNode treeBuilder(vector<int> input) {

    // vector holding Node pointers in identical order to input vector
    vector<TreeNode*> nodeArray;
    // create Node and add its pointer to index 0 (this node will be returned later)
    nodeArray.push_back(&TreeNode(input[0]));

    int branchIndex = 0; // tracks which node we're adding leaves to 
    int leafIndex = 1; // tracks which input index is being added
    int branchLeaves = 0; // tracks which side were adding to and when node has both and needs to go to next node

    while (leafIndex < input.size()) {

        nodeArray.push_back(&TreeNode(input[leafIndex]));

        if (branchLeaves == 0) {
            nodeArray[branchIndex]->left = nodeArray[leafIndex];
            branchLeaves++;
        }
        else {
            nodeArray[branchIndex]->right = nodeArray[leafIndex];
            branchIndex++;
            branchLeaves = 0;
        }
        leafIndex++;
    }
    return *nodeArray[0];    
};

// Another helper function for testing treeBuilder function
void treePrinter(TreeNode head) {
    queue<TreeNode*> row;
    queue<TreeNode*> next;
    row.push(&head);

    while(!row.empty() && !next.empty()) {
        for
    }
    

}

// bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
// }

// The solution
void main() {



}