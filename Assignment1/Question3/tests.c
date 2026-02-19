#include "Student.h"
#include <stdio.h>
#include <stdlib.h>

static void print_array(const int* a, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        if (i) printf(",");
        printf("%d", a[i]);
    }
    printf("]");
}

static int arrays_equal(const int* a, int n, const int* b, int m) {
    if (n != m) return 0;
    for (int i = 0; i < n; i++) if (a[i] != b[i]) return 0;
    return 1;
}

static int run_one(const int* input, int n, const int* expected, int expN, const char* name) {
    int* digits = (int*)malloc((size_t)n * sizeof(int));
    if (!digits) {
        printf("FAIL: %s (malloc failed)\n", name);
        return 0;
    }
    for (int i = 0; i < n; i++) digits[i] = input[i];

    int retSize = -1;
    int* out = plusOne(digits, n, &retSize);

    int ok = (out != NULL) && arrays_equal(out, retSize, expected, expN);

    if (ok) {
        printf("PASS: %s | input=", name);
        print_array(input, n);
        printf(" got=");
        print_array(out, retSize);
        printf("\n");
    } else {
        printf("FAIL: %s | input=", name);
        print_array(input, n);
        printf(" got=");
        if (!out) printf("NULL");
        else print_array(out, retSize);
        printf(" expected=");
        print_array(expected, expN);
        printf("\n");
    }

    free(digits);
    free(out);
    return ok;
}

void run_all_tests_q3(void) {
    int passed = 0, total = 0;

    // Provided examples
    { int in[] = {1,2,3}; int ex[] = {1,2,4};
      total++; passed += run_one(in, 3, ex, 3, "Example 1"); }

    { int in[] = {4,3,2,1}; int ex[] = {4,3,2,2};
      total++; passed += run_one(in, 4, ex, 4, "Example 2"); }

    { int in[] = {9}; int ex[] = {1,0};
      total++; passed += run_one(in, 1, ex, 2, "Example 3"); }

    // More cases

    // No carry needed, last digit < 9
    { int in[] = {0}; int ex[] = {1};
      total++; passed += run_one(in, 1, ex, 1, "single 0 -> 1"); }

    { int in[] = {8}; int ex[] = {9};
      total++; passed += run_one(in, 1, ex, 1, "single 8 -> 9"); }

    // Carry only on last digit
    { int in[] = {1,2,9}; int ex[] = {1,3,0};
      total++; passed += run_one(in, 3, ex, 3, "carry last digit"); }

    // Carry chain in middle
    { int in[] = {1,9,9}; int ex[] = {2,0,0};
      total++; passed += run_one(in, 3, ex, 3, "carry chain"); }

    // All 9s various lengths
    { int in[] = {9,9}; int ex[] = {1,0,0};
      total++; passed += run_one(in, 2, ex, 3, "all 9s len2"); }

    { int in[] = {9,9,9,9,9}; int ex[] = {1,0,0,0,0,0};
      total++; passed += run_one(in, 5, ex, 6, "all 9s len5"); }

    // Leading digit changes but not all 9
    { int in[] = {2,9,9,9}; int ex[] = {3,0,0,0};
      total++; passed += run_one(in, 4, ex, 4, "2999 -> 3000"); }

    // Long deterministic case length 100: 100..0? (easy check)
    {
        enum { N = 100 };
        int in[N];
        int ex[N];
        for (int i = 0; i < N; i++) { in[i] = 0; ex[i] = 0; }
        // number is 000...000 (but note: real LeetCode says no leading 0; for lab it’s okay)
        // plus one => ...001
        ex[N-1] = 1;
        total++; passed += run_one(in, N, ex, N, "len100 all zeros -> last digit 1");
    }

    // Another long carry chain: 1 followed by 99 nines (length 100)
    {
        enum { N = 100 };
        int in[N];
        int ex[N];
        in[0] = 1;
        ex[0] = 2;
        for (int i = 1; i < N; i++) { in[i] = 9; ex[i] = 0; }
        total++; passed += run_one(in, N, ex, N, "len100: 1 + 99 nines");
    }

    printf("\nSummary: %d/%d tests passed.\n", passed, total);
    if (passed != total) exit(1);
}
