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
ListNode* reverseList(ListNode* head);
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
ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode* leader = head->next;
    //head can't point anywhere
    head->next = nullptr;
    ListNode* current = head;
    ListNode* previous = head;

    while (leader->next != nullptr) {
        // current catches up to leader, leaves behind previous
        current = leader;
        // leader follows pointer before it's changed
        leader = leader->next;
        // current.next 'direction' changed
        current->next = previous;
        // previous catches up using current pointer
        previous = current;
    }
    // leader is now in head position of reversed LL
    // it just needs to be linked to the others
    leader->next = current;

    return leader;
};

// Keep test function clean
void testReverse(ListNode* head) {

    ListNode* forwardptr = head;
        while (forwardptr->next != nullptr){
            cout << forwardptr->val << " ";
            forwardptr = forwardptr->next;
        }
        cout << forwardptr->val << endl;

    head = reverseList(head);

    forwardptr = head;
        while (forwardptr->next != nullptr){
            cout << forwardptr->val << " ";
            forwardptr = forwardptr->next;
        }
        cout << forwardptr->val << endl;
};