// Question1/student.h
// ------------------------------------------------------------
// CS Lab03 - Reverse Linked List
//
// Implement:
//   struct ListNode* reverseList(struct ListNode* head);
//
// Given the head of a singly linked list, reverse the list and
// return the new head.
//
// Notes:
// - Reverse in-place (no new nodes).
// - O(n) time, O(1) extra space expected.
//
// Example:
//   1 -> 2 -> 3 -> NULL
// becomes
//   3 -> 2 -> 1 -> NULL
// ------------------------------------------------------------

#ifndef STUDENT_H
#define STUDENT_H

#include <stddef.h>   
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head);

#endif