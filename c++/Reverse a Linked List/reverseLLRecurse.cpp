#include <iostream>

using namespace std;

// Node of singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* reverseListRecurse(ListNode* head);
ListNode* recurseflip(ListNode* cur, ListNode* nxt);
void testReverse(ListNode* head);

// Test
int main() {
    ListNode test1Tail(5);
    ListNode test1_3(4, &test1Tail);
    ListNode test1_2(3, &test1_3);
    ListNode test1_1(2, &test1_2);
    ListNode test1Head(1, &test1_1); 

    testReverse(&test1Head);

    return 0;
}

// The problem function
ListNode* reverseListRecurse(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode* newhead;
    return recurseflip(head, head->next);
};

ListNode* recurseflip(ListNode* cur, ListNode* nxt) {
    // just looks better out here, I think
    ListNode* newhead;
    // current head must point to null outside stack to avoid
    // unnecessarily pointing every cur to null
    cur->next = nullptr;

    if (nxt->next != nullptr) {
        newhead = recurseflip(nxt, nxt->next);
    }
    else {
        newhead = nxt;
    }
    nxt->next = cur;
    return newhead;
};


// Keep test function clean
void testReverse(ListNode* head) {

    ListNode* forwardptr = head;
        while (forwardptr->next != nullptr){
            cout << forwardptr->val << " ";
            forwardptr = forwardptr->next;
        }
        cout << forwardptr->val << endl;

    ListNode* newhead = reverseListRecurse(head);

    forwardptr = newhead;
        while (forwardptr->next != nullptr){
            cout << forwardptr->val << " ";
            forwardptr = forwardptr->next;
        }
        cout << forwardptr->val << endl;
};