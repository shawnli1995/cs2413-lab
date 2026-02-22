// Question3/student.h
// ------------------------------------------------------------
// CS Lab03 - Linked List Cycle
//
// Implement:
//   bool hasCycle(struct ListNode *head);
//
// Return true if the linked list has a cycle, else false.
//
// Requirements:
// - Do not modify the list.
// - O(n) time, O(1) extra space expected.
// - Use fast/slow pointer (Floyd's cycle detection).
// ------------------------------------------------------------

#ifndef STUDENT_H
#define STUDENT_H

#include <stddef.h>   // NULL
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head);

#endif