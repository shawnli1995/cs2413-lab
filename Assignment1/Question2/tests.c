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

static int run_one(const int* input, int n, int expected, const char* name) {
    int* nums = (int*)malloc((size_t)n * sizeof(int));
    if (!nums) {
        printf("FAIL: %s (malloc failed)\n", name);
        return 0;
    }
    for (int i = 0; i < n; i++) nums[i] = input[i];

    int got = majorityElement(nums, n);
    int ok = (got == expected);

    if (ok) {
        printf("PASS: %s | input=", name);
        print_array(input, n);
        printf(" got=%d\n", got);
    } else {
        printf("FAIL: %s | input=", name);
        print_array(input, n);
        printf(" got=%d expected=%d\n", got, expected);
    }

    free(nums);
    return ok;
}

void run_all_tests_q2(void) {
    int passed = 0, total = 0;

    // Provided examples
    { int in[] = {3,2,3}; total++; passed += run_one(in, 3, 3, "Example 1"); }
    { int in[] = {2,2,1,1,1,2,2}; total++; passed += run_one(in, 7, 2, "Example 2"); }

    // More cases

    // Size 1
    { int in[] = {42}; total++; passed += run_one(in, 1, 42, "size 1"); }

    // All same
    { int in[] = {7,7,7,7,7}; total++; passed += run_one(in, 5, 7, "all same"); }

    // Majority negative
    { int in[] = {-1,-1,-1,2,3,-1,4}; total++; passed += run_one(in, 7, -1, "majority negative"); }

    // Majority appears just over n/2
    { int in[] = {9,1,9,2,9,3,9}; total++; passed += run_one(in, 7, 9, "just over half"); }

    // Majority at the end
    { int in[] = {1,2,3,4,5,6,6,6,6,6,6}; total++; passed += run_one(in, 11, 6, "majority at end"); }

    // Majority at the beginning
    { int in[] = {5,5,5,5,5,1,2,3,4}; total++; passed += run_one(in, 9, 5, "majority at beginning"); }

    // Alternating but majority exists
    { int in[] = {1,2,1,2,1,2,1}; total++; passed += run_one(in, 7, 1, "alternating"); }

    // Large deterministic (1001 elements): majority = 100
    {
        enum { N = 1001 };
        int* arr = (int*)malloc(N * sizeof(int));
        if (!arr) {
            printf("FAIL: large deterministic (malloc failed)\n");
        } else {
            // Put 501 copies of 100, and 500 distinct others
            for (int i = 0; i < 501; i++) arr[i] = 100;
            for (int i = 501; i < N; i++) arr[i] = i; // not 100
            total++; passed += run_one(arr, N, 100, "large deterministic (1001)");
            free(arr);
        }
    }

    printf("\nSummary: %d/%d tests passed.\n", passed, total);
    if (passed != total) exit(1);
}
