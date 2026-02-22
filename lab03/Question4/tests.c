#include "student.h"
#include <stdio.h>
#include <stdlib.h>

static struct ListNode* make_list(const int *a, int n) {
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

static void free_list(struct ListNode *head) {
    while (head) {
        struct ListNode *next = head->next;
        free(head);
        head = next;
    }
}

static int run_one(const char *name, const int *in, int n, int expected) {
    struct ListNode *h = make_list(in, n);
    int got = middleNodeValue(h);
    if (got != expected) {
        printf("FAIL: %s expected=%d got=%d\n", name, expected, got);
        free_list(h);
        return 0;
    }
    printf("PASS: %s\n", name);
    free_list(h);
    return 1;
}

int run_tests(void) {
    int pass = 0, total = 0;

    // single
    {
        int in[] = {7};
        total++; pass += run_one("single", in, 1, 7);
    }

    // two -> second middle
    {
        int in[] = {1, 2};
        total++; pass += run_one("two_second_middle", in, 2, 2);
    }

    // three
    {
        int in[] = {1, 2, 3};
        total++; pass += run_one("three", in, 3, 2);
    }

    // four -> second middle is element 3
    {
        int in[] = {10, 20, 30, 40};
        total++; pass += run_one("four_second_middle", in, 4, 30);
    }

    // five
    {
        int in[] = {1, 2, 3, 4, 5};
        total++; pass += run_one("five", in, 5, 3);
    }

    // six -> second middle is element 4
    {
        int in[] = {1, 2, 3, 4, 5, 6};
        total++; pass += run_one("six_second_middle", in, 6, 4);
    }

    // values with duplicates
    {
        int in[] = {9, 9, 9, 9, 9, 9, 9};
        total++; pass += run_one("duplicates", in, 7, 9);
    }

    printf("\nSummary: %d/%d tests passed.\n", pass, total);
    return (pass == total) ? 0 : 1;
}