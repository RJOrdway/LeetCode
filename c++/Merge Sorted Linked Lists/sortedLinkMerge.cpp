#include <iostream>

using namespace std;

int main() {
    // test1 list1
    ListNode test1_1_2 = ListNode(4);
    ListNode test1_1_1 = ListNode(2, &test1_1_2);
    ListNode test1_1_0 = ListNode(1, &test1_1_1);
    // test1 list2
    ListNode test1_2_2 = ListNode(4);
    ListNode test1_2_1 = ListNode(3, &test1_2_2);
    ListNode test1_2_0 = ListNode(1, &test1_2_1);

}


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    ListNode* head;

    if (list1 == nullptr)
        return list2;
    else if (list2 == nullptr)
        return list1;
    else {
        if (list1->val <= list2->val) {
            head = list1;
            list1 = list1->next;
        }
        else {
            head = list2;
            list2 = list2->next;
        }

        ListNode* tail = head;

        while (list1 != nullptr && list2 != nullptr) {

            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            }
            else {
                tail->next = list2;
                list2 = list2->next;
            }

            tail = tail->next;
        }

        if (list1 == nullptr) {
            tail->next = list2;
        }
        else {
            tail->next = list1;
        }

        return head;
    }
};