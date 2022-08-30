/*
 * RJOrdway
 * 1st Solution, LeetCode 142: Linked List Cycle II
 * 
 * Method:  Set of pointers tracking visted nodes
 * 
 * Note:    Coding done in LeetCode's online editor,
 *          class Solution copied for recording.
 * 
 * Started:     8/11/22
 * Submitted:   8/11/22
 */

#include <set>
using namespace std;

// Included struct
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> x;
        while(head != nullptr) {
            if (x.find(head) != x.end())
                return head;
            else {
                x.insert(head);
                head = head->next;
            }
        }
        // no loop
        return nullptr;
    }
};