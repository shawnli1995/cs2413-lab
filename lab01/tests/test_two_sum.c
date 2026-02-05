#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "two_sum.h"

#ifndef BENCHMARK
#define BENCHMARK 1
#endif

static double cpu_ms(clock_t start, clock_t end) {
    return 1000.0 * (double)(end - start) / (double)CLOCKS_PER_SEC;
}

static int fail_count = 0;

static void expect(int condition, const char* test_name, const char* msg) {
    if (!condition) {
        fail_count++;
        printf("[FAIL] %s: %s\n", test_name, msg);
    } else {
        printf("[PASS] %s\n", test_name);
    }
}

/* Validate any returned solution for the "int index" API:
   int two_sum(const int* nums, int n, int target, int* out_i, int* out_j)
*/
static int validate_solution(
    const char* name,
    const int* nums,
    int n,
    int target,
    int ok,
    int i,
    int j
) {
    if (!ok) {
        expect(0, name, "two_sum returned 0 (no solution), but a solution is expected.");
        return 0;
    }

    if (n < 2) {
        expect(0, name, "n < 2 but two_sum returned 1.");
        return 0;
    }

    if (i < 0 || j < 0 || i >= n || j >= n) {
        char buf[200];
        snprintf(buf, sizeof(buf),
                 "indices out of range. got i=%d j=%d, n=%d", i, j, n);
        expect(0, name, buf);
        return 0;
    }
    if (i == j) {
        expect(0, name, "used the same element twice (i == j).");
        return 0;
    }
    if (!(i < j)) {
        char buf[200];
        snprintf(buf, sizeof(buf), "expected i<j, got i=%d j=%d", i, j);
        expect(0, name, buf);
        return 0;
    }

    /* Use long long to avoid signed overflow UB in the test itself. */
    long long sum = (long long)nums[i] + (long long)nums[j];
    if (sum != (long long)target) {
        char buf[240];
        snprintf(buf, sizeof(buf),
                 "wrong pair. nums[i]+nums[j]=%d+%d=%lld, target=%d (i=%d j=%d)",
                 nums[i], nums[j], sum, target, i, j);
        expect(0, name, buf);
        return 0;
    }

    return 1;
}

/* Case where we expect a solution and (exp_i, exp_j) is the UNIQUE valid pair. */
static void run_case_unique(
    const char* name,
    const int* nums,
    int n,
    int target,
    int exp_i,
    int exp_j
) {
    int i = -1, j = -1;
    int ok = two_sum(nums, n, target, &i, &j);

    if (!validate_solution(name, nums, n, target, ok, i, j)) return;

    if (!(i == exp_i && j == exp_j)) {
        char buf[260];
        snprintf(buf, sizeof(buf),
                 "wrong indices. expected (%d,%d), got (%d,%d)",
                 exp_i, exp_j, i, j);
        expect(0, name, buf);
        return;
    }

    expect(1, name, "ok");
}

/* Case where we expect a solution but there may be MULTIPLE correct answers.
   We accept ANY valid (i,j) that satisfies the requirements. */
static void run_case_any(
    const char* name,
    const int* nums,
    int n,
    int target
) {
    int i = -1, j = -1;
    int ok = two_sum(nums, n, target, &i, &j);

    if (!validate_solution(name, nums, n, target, ok, i, j)) return;

    expect(1, name, "ok");
}

/* Case where we expect NO solution (two_sum must return 0). */
static void run_case_no_solution(
    const char* name,
    const int* nums,
    int n,
    int target
) {
    int i = 123, j = 456; /* sentinel */
    int ok = two_sum(nums, n, target, &i, &j);

    if (ok) {
        char buf[240];
        long long sum = 0;
        if (nums && n > 0 && i >= 0 && j >= 0 && i < n && j < n) {
            sum = (long long)nums[i] + (long long)nums[j];
        }
        snprintf(buf, sizeof(buf),
                 "expected no solution (return 0), but got return=1 with i=%d j=%d (sum=%lld)",
                 i, j, sum);
        expect(0, name, buf);
        return;
    }

    expect(1, name, "ok");
}

static void benchmark_two_sum(void) {
    printf("\n=== Self-benchmark (CPU time, for self-comparison only) ===\n");

    const int n = 2000;      /* adjust as desired */
    const int reps = 2000;   /* adjust as desired (higher = more stable) */

    int* nums = (int*)malloc((size_t)n * sizeof(int));
    if (!nums) {
        printf("[WARN] benchmark skipped (malloc failed)\n");
        return;
    }

    for (int k = 0; k < n; k++) nums[k] = k;

    /* A target that definitely has solutions in this array (not necessarily unique). */
    const int target = 42 + 1999;

    int out_i = 0, out_j = 0;

    clock_t t0 = clock();
    for (int r = 0; r < reps; r++) {
        (void)two_sum(nums, n, target, &out_i, &out_j);
    }
    clock_t t1 = clock();

    double total = cpu_ms(t0, t1);
    double per_call_us = (total * 1000.0) / reps;

    printf("n=%d, reps=%d\n", n, reps);
    printf("total_cpu_time=%.2f ms\n", total);
    printf("avg_per_call=%.3f us\n", per_call_us);

    free(nums);
}

int main(void) {
    /* --- Core tests (unique answers) --- */
    {
        int nums[] = { 2, 7, 11, 15 };
        run_case_unique("basic_example", nums, 4, 9, 0, 1);
    }
    {
        int nums[] = { 3, 2, 4 };
        run_case_unique("middle_pair", nums, 3, 6, 1, 2);
    }
    {
        int nums[] = { 3, 3 };
        run_case_unique("duplicate_values", nums, 2, 6, 0, 1);
    }
    {
        int nums[] = { -1, -2, -3, -4, -5 };
        run_case_unique("negatives", nums, 5, -8, 2, 4); /* -3 + -5 */
    }
    {
        int nums[] = { 0, 4, 3, 0 };
        run_case_unique("zeros", nums, 4, 0, 0, 3);
    }

    /* --- Additional correctness/edge tests --- */

    /* Solution at the ends of the array (unique). */
    {
        int nums[] = { 8, 1, 2, 7 };
        run_case_unique("ends_pair_unique", nums, 4, 15, 0, 3);
    }

    /* Duplicates with multiple valid answers: accept any correct pair. */
    {
        int nums[] = { 1, 1, 1, 2 };
        run_case_any("many_duplicates_any", nums, 4, 3);
    }

    /* Large magnitudes (safe; no overflow in the check). */
    {
        int nums[] = { 1000000000, -1000000000, 7, 13 };
        run_case_unique("large_magnitudes_unique", nums, 4, 0, 0, 1);
    }

    /* Multiple-solution cases: accept any valid answer. */
    {
        int nums[] = { -10, 20, 3, 7 };
        run_case_any("multiple_solutions_mixed_signs", nums, 4, 10); /* (-10,20) or (3,7) */
    }
    {
        int nums[] = { 1, 2, 3, 4, 5 };
        run_case_any("multiple_solutions_small", nums, 5, 6); /* (1,5) or (2,4) etc. */
    }

    /* No-solution cases. */
    {
        int nums[] = { 1, 2, 3 };
        run_case_no_solution("no_solution_small", nums, 3, 7);
    }
    {
        int nums[] = { 0, 0, 0 };
        run_case_no_solution("no_solution_all_zeros", nums, 3, 1);
    }
    {
        int nums[] = { 1, 2 };
        run_case_no_solution("no_solution_two_elements", nums, 2, 10);
    }
    {
        int nums[] = { 5 };
        run_case_no_solution("no_solution_single_element", nums, 1, 5);
    }
    {
        /* n=0 is a valid input for the function signature; should return 0. */
        run_case_no_solution("no_solution_empty_array", NULL, 0, 0);
    }

#if BENCHMARK
    benchmark_two_sum();
#else
    printf("\n[Benchmark disabled]\n");
#endif

    if (fail_count == 0) {
        printf("\nALL TESTS PASSED\n");
        return 0;
    } else {
        printf("\n%d TEST(S) FAILED\n", fail_count);
        return 1;
    }
}
