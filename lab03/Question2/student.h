// Question2/student.h
// ------------------------------------------------------------
// CS Lab03 - Swap Nodes in Pairs
//
// Implement:
//   struct ListNode* swapPairs(struct ListNode* head);
//
// Given the head of a singly linked list, swap every two adjacent
// nodes and return the new head.
//
// IMPORTANT:
// - You must swap nodes by changing pointers.
// - Do NOT swap node values.
// - O(n) time, O(1) extra space expected.
//
// Example:
//   1 -> 2 -> 3 -> 4 -> NULL
// becomes
//   2 -> 1 -> 4 -> 3 -> NULL
// ------------------------------------------------------------

#ifndef STUDENT_H
#define STUDENT_H

#include <stddef.h>   // NULL
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head);

#endif