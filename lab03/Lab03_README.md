# CS Lab03 -- Linked List Practice

This lab focuses on Linked List.

# Question 1 -- Reverse Linked List


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


# Question 2 -- Swap Nodes in Pairs

Function to implement:

    struct ListNode* swapPairs(struct ListNode* head);

Description: Given a singly linked list, swap every two adjacent nodes
and return the new head.

IMPORTANT: - You must swap nodes (rewire pointers) - Do NOT swap
values - Do NOT allocate new nodes - O(n) time, O(1) space

  -------------------------
  Example A (Even Length)
  -------------------------

Input: 1 -\> 2 -\> 3 -\> 4 -\> NULL

Step-by-step pairing: (1,2) (3,4)

Output: 2 -\> 1 -\> 4 -\> 3 -\> NULL

  ------------------------
  Example B (Odd Length)
  ------------------------

Input: 1 -\> 2 -\> 3 -\> 4 -\> 5 -\> NULL

Pairs: (1,2) (3,4) 5

Output: 2 -\> 1 -\> 4 -\> 3 -\> 5 -\> NULL

Notice: If the number of nodes is odd, the last node remains unchanged.

Command to test:

    make run2


# Question 3 -- Linked List Cycle 

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


# Question 4 -- Middle Node of a Linked List


Function to implement:

    int middleNodeValue(struct ListNode* head);

Description: Return the value of the middle node.

If the list has an even number of nodes, return the SECOND middle node.


  ------------------------
  Example A (Odd Length)
  ------------------------

Input: 1 -\> 2 -\> 3 -\> 4 -\> 5 -\> NULL

Middle: 3

  ------------------------------------
  Example B (Even Length -- 4 Nodes)
  ------------------------------------

Input: 1 -\> 2 -\> 3 -\> 4 -\> NULL

Positions: 1 2 3 4 ↑ ↑ first second

Two middle nodes: 2 and 3 Return the SECOND middle → 3

Hints: - Use fast/slow pointer technique. - Do NOT allocate new
nodes. - Time complexity: O(n) - Space complexity: O(1)

Command to test:

    make run4


# General Instructions

Compile and run default (Question 1):

    make

Run specific question:

    make run1
    make run2
    make run3
    make run4

Clean all binaries:

    make clean

