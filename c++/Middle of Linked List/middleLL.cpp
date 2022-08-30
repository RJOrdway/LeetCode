/*
 * RJOrdway
 * 1st Solution, LeetCode 876: Middle of the Linked List
 * 
 * Method:  Two node pointers, the leader advances every
 *          iteration, and every second iteration the target
 *          (head) will advance.
 * 
 * Note:    Coding done in LeetCode's online editor,
 *          class Solution copied for recording.
 * Note:    I had previously completed this problem
 *          on 4/11/22 using C#
 * 
 * Started:     8/11/22
 * Submitted:   8/11/22 
 */


// Struct Included with Problem:
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* lead = head;
        for (int i = 0; lead->next != nullptr; i++) {
            if (i%2 == 0)
                head = head->next;
            lead = lead->next;
        }
        return head;
    }
};