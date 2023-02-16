/*
 * RJOrdway
 * 1st Solution, LeetCode 2: Add Two Numbers
 * 
 * Method: # Modify Linked List l1 in place, 
 *         # Ensure each node remains below 10 and add a +1 "carry" counter to 
 *           next node when applicible
 *         # Move through both lists in sync and add l2 node value to l1 node 
 *           value (+ carry)
 *         # When either list ends, do the following:
 *              ## If l2 has more nodes, link remainder of l2 to end of l1
 *              ## Add any remaining "carry" value to next l1 node (if applicable)
 *              ## If there is a carry but no l1 nodes left, link new node(1) on
 *                 final node
 *              ## return l1
 * 
 * 
 * Concern: # Could swap "carry" from int to bool
 *          # Had odd "Address Sanitizer stack-buffer-overflow error" only on leetcode
 *            when using 
 *             
 *              if (carry == 1) {
 *                   ListNode end = ListNode(1);
 *                   l1Current->next = &end;
 *              }
 * 
 *            but not with
 * 
 *              if (carry == 1)
 *                  l1Current->next = new ListNode(1);
 * 
 * 
 * 
 * Result:  Surprisingly good!
 *          Runtime 28 ms
 *           Beats 92.48%
 *           Memory 70.9 MB
 *           Beats 94.64%
 * 
 * Started:     02/12/23
 * Submitted:   02/12/23
 */

 // Definition for singly-linked list. {From LeetCode Problem}
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
// My Solution
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int current = 0;
    int carry = 0;
    ListNode* l1Current = l1;
    ListNode* l2Current = l2;
    while (l1Current->next != nullptr && l2Current->next != nullptr) {
        current = l1Current->val + l2Current->val + carry;
        if (current > 9) {
            current = current - 10;
            carry = 1;
        }
        else
            carry = 0;
        l1Current->val = current;
        l1Current = l1Current->next;
        l2Current = l2Current->next;
    }
    // Final normal cycle
    current = l1Current->val + l2Current->val + carry;
    if (current > 9) {
        current = current - 10;
        carry = 1;
    }
    else
        carry = 0;
    l1Current->val = current;

    // Case l2 is longer - l1Current->next is null
    // Hook valid l2Current->next to l1Current->next
    if (l2Current->next != nullptr)
        l1Current->next = l2Current->next;

    // Case l1 is longer (or has had new nodes added from l2)
    if (l1Current->next != nullptr) {
        // prepare for as many 9's with digit carry over as possible
        while (carry != 0 && l1Current->next != nullptr) {
            l1Current = l1Current->next;
            l1Current->val = l1Current->val + carry;
            if (l1Current->val > 9)
                l1Current->val = 0;
            else
                carry = 0;
        }
    }

    // Case 3 - l1 & l2 are equal 
    // or end of Case 1 or 2
    // if carry = 1 after loop, add one last node

/*
    // LeetCode Hates this version
    // Gets Address Sanitizer error runtime error 31 stack-buffer-overflow
    if (carry == 1) {
        ListNode end = ListNode(1);
        l1Current->next = &end;
    }
*/

    // LeetCode Approved
    l1Current->next = new ListNode(1);


    // now we have updated as many l1 nodes as required
    return l1;
};

int main() {
    // test 1
    ListNode t1l1 = ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode* test1L1 = &t1l1;
    ListNode t1l2 = ListNode(5, new ListNode(6, new ListNode(4)));
    ListNode* test1L2 = &t1l2;
    ListNode test1Solution = ListNode(7, new ListNode(0, new ListNode(8)));

    ListNode* test1Result = addTwoNumbers(test1L1, test1L2);

    // test 2

    ListNode t2l1 = ListNode(0);
    ListNode* test2L1 = &t2l1;
    ListNode t2l2 = ListNode(0);
    ListNode* test2L2 = &t2l2;

    ListNode* test2Result = addTwoNumbers(test2L1, test2L2);

    ListNode t3l1 = ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))))));
    ListNode t3l2 = ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))));

    ListNode* test3Result = addTwoNumbers(&t3l1, &t3l2);

    return 1;



}