# CS Lab03 -- Linked List Practice

This lab focuses on Linked List.

Folder structure:

Lab03/ ├── Makefile ├── Question1/ (Reverse Linked List) ├── Question2/
(Swap Nodes in Pairs) ├── Question3/ (Linked List Cycle Detection) ├──
Question4/ (Middle Node of Linked List)


Question 1 -- Reverse Linked List


Function to implement:

    struct ListNode* reverseList(struct ListNode* head);

Description: Given the head of a singly linked list, reverse the list
in-place and return the new head.

Requirements: - Do NOT allocate new nodes. - Do NOT use recursion. -
Time complexity: O(n) - Space complexity: O(1)

Example:

Input: 1 -\> 2 -\> 3 -\> 4 -\> NULL

Output: 4 -\> 3 -\> 2 -\> 1 -\> NULL

Command to test:

    make run1

============================================================ 
Question 2 -- Swap Nodes in Pairs
============================================================

Function to implement:

    struct ListNode* swapPairs(struct ListNode* head);

Description: Given a singly linked list, swap every two adjacent nodes
and return the new head.

IMPORTANT: - You must swap nodes by changing pointers. - Do NOT swap
node values. - Do NOT allocate new nodes. - Time complexity: O(n) -
Space complexity: O(1)

Example:

Input: 1 -\> 2 -\> 3 -\> 4 -\> NULL

Output: 2 -\> 1 -\> 4 -\> 3 -\> NULL

Command to test:

    make run2

============================================================ 
Question 3 -- Linked List Cycle 
============================================================

Function to implement:

    bool hasCycle(struct ListNode* head);

Description: Determine whether a linked list contains a cycle.

Requirements: - Do NOT modify the linked list.  - Time complexity: O(n) -
Space complexity: O(1)
Hints: Use two pointers: - slow moves one step at a time - fast
moves two steps at a time

If they ever meet, a cycle exists.

Command to test:

    make run3

============================================================ 
Question 4 -- Middle Node of a Linked List
============================================================

Function to implement:

    int middleNodeValue(struct ListNode* head);

Description: Return the value of the middle node.

If the list has an even number of nodes, return the SECOND middle node.

Example:

Input: 1 -\> 2 -\> 3 -\> 4 -\> NULL

Output: 3

Explanation: Two middle nodes are 2 and 3. Return the second one (3).

Hints: - Use fast/slow pointer technique. - Do NOT allocate new
nodes. - Time complexity: O(n) - Space complexity: O(1)

Command to test:

    make run4

============================================================ 
General Instructions
============================================================

Compile and run default (Question 1):

    make

Run specific question:

    make run1
    make run2
    make run3
    make run4

Clean all binaries:

    make clean

