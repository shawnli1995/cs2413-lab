// Question1/tests.c
// ------------------------------------------------------------
// Tests for reverseList 
// ------------------------------------------------------------

#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    // Guard against cycles: free at most max_nodes nodes.
    while (head && max_nodes-- > 0) {
        struct ListNode *next = head->next;
        free(head);
        head = next;
    }
}

static int list_to_array_limited(struct ListNode *head, int *out, int cap) {
    // Guard against cycles: collect at most cap nodes.
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

static int run_one(const char *name, const int *in, int in_n, const int *exp, int exp_n) {
    struct ListNode *head = make_list(in, in_n);
    struct ListNode *rev = reverseList(head);

    // Use a cap to avoid infinite loops if student accidentally creates a cycle.
    int got[2048];
    int got_n = list_to_array_limited(rev, got, 2048);

    int ok = expect_array(got, got_n, exp, exp_n);

    if (!ok) {
        printf("FAIL: %s\n", name);
        printf("  input="); print_array(in, in_n); printf("\n");
        printf("  expected="); print_array(exp, exp_n); printf("\n");
        printf("  got="); print_array(got, got_n); printf("\n");

        // Helpful hint if we suspect a cycle:
        if (got_n == 2048) {
            printf("  note: output hit safety cap (possible cycle)\n");
        }
    } else {
        printf("PASS: %s\n", name);
    }

    free_list_limited(rev, 4096);
    return ok ? 1 : 0;
}

static void build_range(int *a, int n, int start) {
    for (int i = 0; i < n; i++) a[i] = start + i;
}

static void reverse_copy(const int *in, int n, int *out) {
    for (int i = 0; i < n; i++) out[i] = in[n - 1 - i];
}

int run_tests(void) {
    int pass = 0, total = 0;

    // 1) empty list
    total++;
    pass += run_one("empty", NULL, 0, NULL, 0);

    // 2) single
    {
        int in[] = {7};
        int exp[] = {7};
        total++;
        pass += run_one("single", in, 1, exp, 1);
    }

    // 3) two nodes
    {
        int in[] = {1, 2};
        int exp[] = {2, 1};
        total++;
        pass += run_one("two", in, 2, exp, 2);
    }

    // 4) five nodes
    {
        int in[] = {1, 2, 3, 4, 5};
        int exp[] = {5, 4, 3, 2, 1};
        total++;
        pass += run_one("five", in, 5, exp, 5);
    }

    // 5) includes negatives and zeros
    {
        int in[] = {0, -1, 2, -3, 0};
        int exp[] = {0, -3, 2, -1, 0};
        total++;
        pass += run_one("mixed", in, 5, exp, 5);
    }

    // 6) all zeros
    {
        int in[] = {0, 0, 0, 0, 0, 0};
        int exp[] = {0, 0, 0, 0, 0, 0};
        total++;
        pass += run_one("all_zeros", in, 6, exp, 6);
    }

    // 7) duplicates
    {
        int in[] = {1, 1, 2, 2, 3, 3};
        int exp[] = {3, 3, 2, 2, 1, 1};
        total++;
        pass += run_one("duplicates", in, 6, exp, 6);
    }

    // 8) palindrome sequence (reversal equals itself)
    {
        int in[] = {1, 2, 3, 2, 1};
        int exp[] = {1, 2, 3, 2, 1};
        total++;
        pass += run_one("palindrome", in, 5, exp, 5);
    }

    // 9) extreme int values
    {
        int in[] = {INT_MIN, -1, 0, 1, INT_MAX};
        int exp[] = {INT_MAX, 1, 0, -1, INT_MIN};
        total++;
        pass += run_one("int_extremes", in, 5, exp, 5);
    }

    // 10) longer list (20)
    {
        int in[20];
        int exp[20];
        build_range(in, 20, 1);       // [1..20]
        reverse_copy(in, 20, exp);    // [20..1]
        total++;
        pass += run_one("len20", in, 20, exp, 20);
    }

    // 11) longer list (101)
    {
        int in[101];
        int exp[101];
        build_range(in, 101, -50);    // [-50..50]
        reverse_copy(in, 101, exp);
        total++;
        pass += run_one("len101", in, 101, exp, 101);
    }

    // 12) stress-ish list (1000)
    // This is still fine for O(n) solutions and helps catch partial-reversal bugs.
    {
        enum { N = 1000 };
        int *in = (int*)malloc(sizeof(int) * N);
        int *exp = (int*)malloc(sizeof(int) * N);
        if (in && exp) {
            build_range(in, N, 0);
            reverse_copy(in, N, exp);
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