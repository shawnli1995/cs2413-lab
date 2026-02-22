// Question2/tests.c
// ------------------------------------------------------------
// Tests for swapPairs 
// ------------------------------------------------------------

#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

static void free_list_limited(struct ListNode *head, int max_nodes) {
    while (head && max_nodes-- > 0) {
        struct ListNode *next = head->next;
        free(head);
        head = next;
    }
}

static int list_to_array_limited(struct ListNode *head, int *out, int cap) {
    int k = 0;
    while (head && k < cap) {
        out[k++] = head->val;
        head = head->next;
    }
    return k;
}

static int expect_array(const int *got, int got_n, const int *exp, int exp_n) {
    if (got_n != exp_n) return 0;
    for (int i = 0; i < exp_n; i++) {
        if (got[i] != exp[i]) return 0;
    }
    return 1;
}

static void print_array(const int *a, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        if (i) printf(",");
        printf("%d", a[i]);
    }
    printf("]");
}

static void swap_pairs_array(const int *in, int n, int *out) {
    // Expected behavior on values (for testing): swap every adjacent pair.
    // If odd length, last element stays.
    for (int i = 0; i < n; i++) out[i] = in[i];
    for (int i = 0; i + 1 < n; i += 2) {
        int t = out[i];
        out[i] = out[i + 1];
        out[i + 1] = t;
    }
}

static int run_one(const char *name, const int *in, int in_n, const int *exp, int exp_n) {
    struct ListNode *head = make_list(in, in_n);
    struct ListNode *out_head = swapPairs(head);

    int got[4096];
    int got_n = list_to_array_limited(out_head, got, 4096);

    int ok = expect_array(got, got_n, exp, exp_n);

    if (!ok) {
        printf("FAIL: %s\n", name);
        printf("  input="); print_array(in, in_n); printf("\n");
        printf("  expected="); print_array(exp, exp_n); printf("\n");
        printf("  got="); print_array(got, got_n); printf("\n");
        if (got_n == 4096) printf("  note: output hit safety cap (possible cycle)\n");
    } else {
        printf("PASS: %s\n", name);
    }

    free_list_limited(out_head, 8192);
    return ok ? 1 : 0;
}

int run_tests(void) {
    int pass = 0, total = 0;
    printf("Test question2: \n");
    // empty
    total++;
    pass += run_one("empty", NULL, 0, NULL, 0);

    // single
    {
        int in[] = {7};
        int exp[] = {7};
        total++;
        pass += run_one("single", in, 1, exp, 1);
    }

    // two
    {
        int in[] = {1, 2};
        int exp[] = {2, 1};
        total++;
        pass += run_one("two", in, 2, exp, 2);
    }

    // three (odd length)
    {
        int in[] = {1, 2, 3};
        int exp[] = {2, 1, 3};
        total++;
        pass += run_one("three", in, 3, exp, 3);
    }

    // four
    {
        int in[] = {1, 2, 3, 4};
        int exp[] = {2, 1, 4, 3};
        total++;
        pass += run_one("four", in, 4, exp, 4);
    }

    // five (odd length)
    {
        int in[] = {1, 2, 3, 4, 5};
        int exp[] = {2, 1, 4, 3, 5};
        total++;
        pass += run_one("five", in, 5, exp, 5);
    }

    // duplicates
    {
        int in[] = {9, 9, 9, 9, 9};
        int exp[] = {9, 9, 9, 9, 9};
        total++;
        pass += run_one("duplicates", in, 5, exp, 5);
    }

    // negatives + zeros
    {
        int in[] = {0, -1, 0, -2, 3, 0};
        int exp[] = {-1, 0, -2, 0, 0, 3};
        total++;
        pass += run_one("mixed", in, 6, exp, 6);
    }

    // int extremes
    {
        int in[] = {INT_MIN, INT_MAX, -1, 0, 1};
        int exp[] = {INT_MAX, INT_MIN, 0, -1, 1};
        total++;
        pass += run_one("int_extremes", in, 5, exp, 5);
    }

    // longer: 20
    {
        int in[20];
        for (int i = 0; i < 20; i++) in[i] = i + 1;
        int exp[20];
        swap_pairs_array(in, 20, exp);
        total++;
        pass += run_one("len20", in, 20, exp, 20);
    }

    // longer odd: 21
    {
        int in[21];
        for (int i = 0; i < 21; i++) in[i] = i;
        int exp[21];
        swap_pairs_array(in, 21, exp);
        total++;
        pass += run_one("len21", in, 21, exp, 21);
    }

    // stress-ish: 1000
    {
        enum { N = 1000 };
        int *in = (int*)malloc(sizeof(int) * N);
        int *exp = (int*)malloc(sizeof(int) * N);
        if (in && exp) {
            for (int i = 0; i < N; i++) in[i] = i;
            swap_pairs_array(in, N, exp);
            total++;
            pass += run_one("len1000", in, N, exp, N);
        } else {
            printf("SKIP: len1000 (malloc failed)\n");
        }
        free(in);
        free(exp);
    }

    printf("\nSummary: %d/%d tests passed.\n", pass, total);
    return (pass == total) ? 0 : 1;
}