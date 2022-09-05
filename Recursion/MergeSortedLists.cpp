#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (!l1 || !l2)
        return l1 ? l1 : l2;

    ListNode *head = NULL;
    if (l1->val < l2->val)
    {
        head = l1;
        head->next = mergeTwoLists(head->next, l2);
    }
    else
    {
        head = l2;
        head->next = mergeTwoLists(l1, head->next);
    }
    return head;
}