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

static int run_one(const int* nums1_in, int nums1Size, int m,
                   const int* nums2_in, int nums2Size, int n,
                   const int* expected, int expSize,
                   const char* name) {
    int* nums1 = (int*)malloc((size_t)nums1Size * sizeof(int));
    int* nums2 = NULL;
    if (nums2Size > 0) nums2 = (int*)malloc((size_t)nums2Size * sizeof(int));

    if (!nums1 || (nums2Size > 0 && !nums2)) {
        printf("FAIL: %s (malloc failed)\n", name);
        free(nums1);
        free(nums2);
        return 0;
    }

    for (int i = 0; i < nums1Size; i++) nums1[i] = nums1_in[i];
    for (int i = 0; i < nums2Size; i++) nums2[i] = nums2_in[i];

    merge(nums1, nums1Size, m, nums2, nums2Size, n);

    int ok = arrays_equal(nums1, nums1Size, expected, expSize);

    if (ok) {
        printf("PASS: %s | result=", name);
        print_array(nums1, nums1Size);
        printf("\n");
    } else {
        printf("FAIL: %s | got=", name);
        print_array(nums1, nums1Size);
        printf(" expected=");
        print_array(expected, expSize);
        printf("\n");
    }

    free(nums1);
    free(nums2);
    return ok;
}

void run_all_tests_q1(void) {
    int passed = 0, total = 0;

    // Provided examples
    {
        int nums1[] = {1,2,3,0,0,0};
        int nums2[] = {2,5,6};
        int expected[] = {1,2,2,3,5,6};
        total++; passed += run_one(nums1, 6, 3, nums2, 3, 3, expected, 6, "Example 1");
    }
    {
        int nums1[] = {1};
        int expected[] = {1};
        total++; passed += run_one(nums1, 1, 1, NULL, 0, 0, expected, 1, "Example 2 (n=0)");
    }
    {
        int nums1[] = {0};
        int nums2[] = {1};
        int expected[] = {1};
        total++; passed += run_one(nums1, 1, 0, nums2, 1, 1, expected, 1, "Example 3 (m=0)");
    }

    // More edge cases

    // All nums2 smaller than nums1
    {
        int nums1[] = {4,5,6,0,0,0};
        int nums2[] = {1,2,3};
        int expected[] = {1,2,3,4,5,6};
        total++; passed += run_one(nums1, 6, 3, nums2, 3, 3, expected, 6, "nums2 all smaller");
    }

    // All nums2 larger than nums1
    {
        int nums1[] = {1,2,3,0,0,0};
        int nums2[] = {4,5,6};
        int expected[] = {1,2,3,4,5,6};
        total++; passed += run_one(nums1, 6, 3, nums2, 3, 3, expected, 6, "nums2 all larger");
    }

    // Interleaving with duplicates
    {
        int nums1[] = {1,2,2,0,0,0};
        int nums2[] = {2,2,3};
        int expected[] = {1,2,2,2,2,3};
        total++; passed += run_one(nums1, 6, 3, nums2, 3, 3, expected, 6, "interleave duplicates");
    }

    // Many duplicates all around
    {
        int nums1[] = {2,2,2,0,0};
        int nums2[] = {2,2};
        int expected[] = {2,2,2,2,2};
        total++; passed += run_one(nums1, 5, 3, nums2, 2, 2, expected, 5, "all same value");
    }

    // Negatives and positives
    {
        int nums1[] = {-5,-3,0,0,0};
        int nums2[] = {-4,-1};
        int expected[] = {-5,-4,-3,-1,0};
        total++; passed += run_one(nums1, 5, 3, nums2, 2, 2, expected, 5, "negatives mixed");
    }

    // nums1 empty part (m=0), nums2 non-empty (more than 1)
    {
        int nums1[] = {0,0,0,0};
        int nums2[] = {-2,0,3,7};
        int expected[] = {-2,0,3,7};
        total++; passed += run_one(nums1, 4, 0, nums2, 4, 4, expected, 4, "m=0, take all nums2");
    }

    // nums2 empty part (n=0) but nums1 has multiple elements
    {
        int nums1[] = {-3,-1,2,4};
        int expected[] = {-3,-1,2,4};
        total++; passed += run_one(nums1, 4, 4, NULL, 0, 0, expected, 4, "n=0, nums1 unchanged");
    }

    // Smallest size merges
    {
        int nums1[] = {2,0};
        int nums2[] = {1};
        int expected[] = {1,2};
        total++; passed += run_one(nums1, 2, 1, nums2, 1, 1, expected, 2, "size2 merge");
    }

    // Large but still quick deterministic case
    {
        enum { M = 50, N = 50, SZ = 100 };
        int* nums1 = (int*)malloc(SZ * sizeof(int));
        int* nums2 = (int*)malloc(N * sizeof(int));
        int* expected = (int*)malloc(SZ * sizeof(int));
        if (!nums1 || !nums2 || !expected) {
            printf("FAIL: large case (malloc failed)\n");
            free(nums1); free(nums2); free(expected);
        } else {
            // nums1: even numbers 0..98 in first 50
            for (int i = 0; i < M; i++) nums1[i] = 2*i;
            for (int i = M; i < SZ; i++) nums1[i] = 0; // placeholders
            // nums2: odd numbers 1..99
            for (int i = 0; i < N; i++) nums2[i] = 2*i + 1;
            // expected 0..99
            for (int i = 0; i < SZ; i++) expected[i] = i;

            total++; passed += run_one(nums1, SZ, M, nums2, N, N, expected, SZ, "large interleave 0..99");
            free(nums1); free(nums2); free(expected);
        }
    }

    printf("\nSummary: %d/%d tests passed.\n", passed, total);
    if (passed != total) exit(1);
}
