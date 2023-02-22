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
#include <deque>
#include <algorithm>

using namespace std;

// Definition for a binary tree node (from LeetCode problem 872 definition)
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// helper function for testing tree building code
void treePrinter(TreeNode head) {
    vector<string> layerHolder;         // holds unmodified
    int n = 1;                          // n tracks the correct width of each tree layer

    // Tree parsing stage
    deque<TreeNode*> row;               // row holds TreeNode pointers that are having their children pointers mapped
    deque<TreeNode*> next;              // next holds children pointers as they are added from the parents
    deque<TreeNode*> temp;              // temp allows us to swap next into row, once row has been emptied
    //bool rightBranch = false;           // keep track of which pointer is being (or would be getting) filled
    
    row.push_back(&head);
    //layerHolder.push_back(to_string(head.val)); // populate top layer (first index) with head value
    layerHolder.push_back("");                  // create empty back for layer 2

    bool validNodesInRow = true;
    
    while (validNodesInRow) {
        if (row.front() != nullptr) {
            next.push_back(row.front()->left);
            next.push_back(row.front()->right);

            if (row.size() > 1) {
                layerHolder.back() += to_string(row.front()->val) + "\t";
                row.pop_front();
            }
            else {
                layerHolder.back() += to_string(row.front()->val);
                row.pop_front();
                // prepare deque swap
                temp = row;
                row = next;
                next = temp;
                // check if next row needs to be added
                for (auto it = row.cbegin(); !validNodesInRow && it != row.cend(); it++) {
                    if (*it != nullptr) {
                        validNodesInRow = true;
                        layerHolder.push_back("");
                        n = n*2;
                    }
                } 
            }
        }
        else {
            next.push_back(nullptr);
            next.push_back(nullptr);

            if (row.size() > 1) {
                layerHolder.back() += " \t";
                row.pop_front();
            }
            else {
                layerHolder.back() += " ";
                row.pop_front();
                // prepare deque swap
                temp = row;
                row = next;
                next = temp;
                // check if next row needs to be added
                for (auto it = row.cbegin(); !validNodesInRow && it != row.cend(); it++) {
                    if (*it != nullptr) {
                        validNodesInRow = true;
                        layerHolder.push_back("");
                        n = n*2;
                    }
                } 
            }
        }
    }
    // begin output parsing
    int layer = 1;
    for (auto it = layerHolder.cbegin(); it != layerHolder.cend(); it++){
        //print left side spacing
        for (int i = layer; i < (n/2); i++) {
            cout << "\t";
        }
        cout << *it;
        for (int i = layer; i < (n/2); i++) {
            cout << "\t";
        }
        layer = layer * 2;
    }
}

// bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
// }



// The solution
int main() {

    // these deques help us build the test trees using LeetCode's binary tree from vector format
    deque<TreeNode*> row;               // row holds TreeNode pointers that are having their children pointers added
    deque<TreeNode*> next;              // next holds children pointers as they are added to their parent
    deque<TreeNode*> temp;              // temp allows us to swap next into row, once row has been emptied

    // These two items comprise test case 1
    vector<int> testIntArray1{3,5,1,6,2,9,8,-1,-1,7,4};         //| Generating vector
    TreeNode head1 = TreeNode(testIntArray1[0]);                //| Resulting Tree head


    // build test 1
    row.push_back(&head1);

    for (int parent = 0, child = 1; child < testIntArray1.size(); child++) {
        // Condition 1: child index is not null 
        if (testIntArray1[child] != -1) {

            TreeNode newBranch = TreeNode(testIntArray1[child]);    // generate new branch
            next.push_back(&newBranch);                                  // add to 'next' deque

            // Condition 1.1: new branch goes to parent left
            if (child % 2 == 1) {
                row.front()->left = &newBranch;
            }
            // Condition 1.2: new branch goes to parent right, pop row front and begin next parent
            else {
                row.front()->right = &newBranch;
                row.pop_front();
                // check if row is empty, if so, rotate
                if (row.empty()) {
                    temp = row;     // ensure 'temp' is empty
                    row = next;     // rotate 'next' to active 'row'
                    next = temp;    // ensure 'next' is empty
                }
            }
        }
        // Condition 2: child index is intended to be null (-1)
        else {
            //Condition 2.1 parent left branch is skipped (no code needed)

            //Condition 2.2 parent right branch is skipped
            if (child % 2 == 0) {
                row.pop_front();
                // check if row is empty, if so, rotate
                if (row.empty()) {
                    temp = row;     // ensure 'temp' is empty
                    row = next;     // rotate 'next' to active 'row'
                    next = temp;    // ensure 'next' is empty
                }
            }
        }
    } // Nodes have been created and arranged

    treePrinter(head1);


    return 0;
}











// DEAD CODE
/*
        // Check if value is zero or positive and thus represents a TreeNode
        if (input[branchIndex] >= 0) {
            if (input[leafIndex] >= 0) {
                // create TreeNode with value from array
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
            else {
                // A Nu
                if (branchLeaves == 0) {
                    branchLeaves++;
                }
                // No TreeNode created and the branch tracker moves to next 
                else {
                    branchIndex++;
                    branchLeaves = 0;
                }
            }
        }
    }
*/

/*
 * Helper function to build test nodes, built by me
 * Notes:
 * Cannot handle empty vectors. Problem constraint specifies each tree will have
 * [1, 200] nodes per tree, we are always assuming there is a head node
 * 
 * Treats -1 as NULL and does not generate a TreeNode for the corresponding leg.
 * Problem constraint specifies node values are [0,200]. Test cases will manually swap
 * NULL to -1
 */
// TreeNode treeBuilder(vector<int> input) {

//     TreeNode head = TreeNode(input[0]); // create head node from index 0, keep variable to return later

//     int parentIndex = 0;                // index of parent node having its children added
//     bool rightBranch = false;          // tracks which parent branch to add child, false = left, true = right
//     int childIndex = 1;                 // index of child node being added to parent
    
//     deque<TreeNode*> row;               // row holds TreeNode pointers that are having their children pointers added
//     deque<TreeNode*> next;              // next holds children pointers as they are added to their parent
//     deque<TreeNode*> temp;              // temp allows us to swap next into row, once row has been emptied

//     row.push(&head);                    // with head in row

//     // we only need to add children until input vector is empty
//     while (childIndex < input.size()) {

//         // confirm next row item is valid and not a null node
//         if (row.front() != nullptr) {
//             if (input[childIndex] == -1) {
//                 if (rightBranch) {
//                     row.pop();
//                     parentIndex++;
//                     if (row.empty()) {
//                         temp = row;
//                         row = next;
//                         next = temp;
//                     }
//                 }
//                 rightBranch = !rightBranch;
//                 childIndex++;
//             }
//             else {
//                 TreeNode nextNode = TreeNode(input[childIndex]);
//                 if (!rightBranch) {
//                     row.front()->left = &nextNode;
//                     next.push(row.front()->left);
//                 }
//                 else {
//                     row.front()->right = &nextNode;
//                     next.push(row.front()->right);
//                     row.pop();  // we are done adding to the row.front(), so we pop it
//                     parentIndex++;
//                     // if row empties out, swap next into active row
//                     if (row.empty()) {
//                         temp = row;
//                         row = next;
//                         next = temp;
//                     }
//                 }
//                 rightBranch = !rightBranch;
//                 childIndex++;
//             }
//         }
//         else {
//             parentIndex++;
//         }

//     }
//     return head;    
// };