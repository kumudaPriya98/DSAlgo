#include <iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };



ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* nextNextNode = swapPairs(head->next->next);
    
    ListNode* temp = head;  
    head = head->next;
    head->next = temp;
    head->next->next = nextNextNode;

    return head;
}