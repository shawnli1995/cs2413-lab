// Question2/student.c
// ------------------------------------------------------------
// CS Lab03 - Swap Nodes in Pairs 
//
// TODO:
//   Implement swapPairs(head) to swap every two adjacent nodes.
//
// Rules:
// - Do not allocate new nodes.
// - Do not swap values; swap nodes (rewire pointers).
// - Return the new head pointer.
// ------------------------------------------------------------
#include "student.h"

struct ListNode* swapPairs(struct ListNode* head) {
      // TODO: implement

    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode* newHead = head->next;
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;

    while (curr != NULL && curr->next != NULL) {

        struct ListNode* second = curr->next;
        struct ListNode* nextPair = second->next;

        second->next = curr;
        curr->next = nextPair;

        if (prev != NULL) {
            prev->next = second;
        }

        prev = curr;
        curr = nextPair;
    }
    return newHead;
}