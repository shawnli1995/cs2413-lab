// Question3/tests.c
// ------------------------------------------------------------
// Tests for hasCycle
// ------------------------------------------------------------

#include "Student.h"
#include <stdio.h>
#include <stdlib.h>

static struct ListNode* make_nodes(const int *a, int n) {
    if (n <= 0) return NULL;
    struct ListNode *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = a[i];
        node->next = NULL;
        if (!head) head = node;
        else tail->next = node;
        tail = node;
    }
    return head;
}

static struct ListNode* get_kth(struct ListNode *head, int k) {
    int i = 0;
    while (head && i < k) {
        head = head->next;
        i++;
    }
    return head;
}

static void free_list_linear(struct ListNode *head) {
    while (head) {
        struct ListNode *next = head->next;
        free(head);
        head = next;
    }
}

static int run_one(const char *name, struct ListNode *head, bool expected) {
    bool got = hasCycle(head);
    if (got != expected) {
        printf("FAIL: %s expected=%s got=%s\n",
               name, expected ? "true" : "false", got ? "true" : "false");
        return 0;
    }
    printf("PASS: %s\n", name);
    return 1;
}

int run_tests(void) {
    int pass = 0, total = 0;

    // 1) empty
    total++;
    pass += run_one("empty", NULL, false);

    // 2) single no cycle
    {
        int a[] = {1};
        struct ListNode *h = make_nodes(a, 1);
        total++;
        pass += run_one("single_no_cycle", h, false);
        free_list_linear(h);
    }

    // 3) single with self-cycle
    {
        int a[] = {1};
        struct ListNode *h = make_nodes(a, 1);
        h->next = h;
        total++;
        pass += run_one("single_self_cycle", h, true);
        h->next = NULL; // break cycle before free
        free_list_linear(h);
    }

    // 4) multi no cycle
    {
        int a[] = {1, 2, 3, 4, 5};
        struct ListNode *h = make_nodes(a, 5);
        total++;
        pass += run_one("five_no_cycle", h, false);
        free_list_linear(h);
    }

    // 5) cycle to head (tail -> head)
    {
        int a[] = {1, 2, 3, 4, 5};
        struct ListNode *h = make_nodes(a, 5);
        struct ListNode *tail = get_kth(h, 4);
        tail->next = h;
        total++;
        pass += run_one("cycle_to_head", h, true);
        tail->next = NULL; // break
        free_list_linear(h);
    }

    // 6) cycle to middle (tail -> node index 2)
    {
        int a[] = {10, 20, 30, 40, 50, 60};
        struct ListNode *h = make_nodes(a, 6);
        struct ListNode *tail = get_kth(h, 5);
        struct ListNode *mid = get_kth(h, 2); // value 30
        tail->next = mid;
        total++;
        pass += run_one("cycle_to_mid", h, true);
        tail->next = NULL; // break
        free_list_linear(h);
    }

    // 7) two nodes no cycle
    {
        int a[] = {1, 2};
        struct ListNode *h = make_nodes(a, 2);
        total++;
        pass += run_one("two_no_cycle", h, false);
        free_list_linear(h);
    }

    // 8) two nodes cycle (2 -> 1)
    {
        int a[] = {1, 2};
        struct ListNode *h = make_nodes(a, 2);
        struct ListNode *tail = get_kth(h, 1);
        tail->next = h;
        total++;
        pass += run_one("two_cycle", h, true);
        tail->next = NULL;
        free_list_linear(h);
    }

    printf("\nSummary: %d/%d tests passed.\n", pass, total);
    return (pass == total) ? 0 : 1;
}