#include <iostream>

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* next = head->next;
    ListNode* newHead = reverseList(next);
    head->next = NULL;
    next->next = head;
    return newHead; 
 }

 ListNode* reverseListIterative(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* reversedNext = NULL;
    while (head) {
        ListNode* next = head->next;
        head->next = reversedNext;

        reversedNext = head;
        head = next;
    }
    return reversedNext;
 }