
// Question4/student.h
// ------------------------------------------------------------
// CS Lab03 - Middle Node of Linked List
//
// Implement:
//   int middleNodeValue(struct ListNode *head);
//
// Return the value of the middle node using fast/slow pointers.
// If the list has even length, return the SECOND middle.
//
// Assumption: head is not NULL in the tests.
// ------------------------------------------------------------

#ifndef STUDENT_H
#define STUDENT_H

#include <stddef.h>   // NULL
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int middleNodeValue(struct ListNode *head);

#endif