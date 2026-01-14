#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "two_sum.h"
#include <time.h>

static double cpu_ms(clock_t start, clock_t end) {
    return 1000.0 * (double)(end - start) / (double)CLOCKS_PER_SEC;
}

static int fail_count = 0;

static void expect(int condition, const char* test_name, const char* msg) {
    if (!condition) {
        fail_count++;
        printf("[FAIL] %s: %s\n", test_name, msg);
    }
    else {
        printf("[PASS] %s\n", test_name);
    }
}

static void run_case(
    const char* name,
    const int* nums,
    size_t n,
    int target,
    size_t exp_i,
    size_t exp_j
) {
    size_t i = (size_t)-1, j = (size_t)-1;
    int ok = two_sum(nums, n, target, &i, &j);

    if (!ok) {
        expect(0, name, "two_sum returned 0 (no solution), but a solution is expected.");
        return;
    }

    // Basic validity checks
    if (!(i < n && j < n)) {
        char buf[200];
        snprintf(buf, sizeof(buf),
            "indices out of range. got i=%zu j=%zu, n=%zu", i, j, n);
        expect(0, name, buf);
        return;
    }
    if (i == j) {
        expect(0, name, "used the same element twice (i == j).");
        return;
    }
    if (!(i < j)) {
        char buf[200];
        snprintf(buf, sizeof(buf), "expected i<j, got i=%zu j=%zu", i, j);
        expect(0, name, buf);
        return;
    }

    // Check correctness of sum
    int sum = nums[i] + nums[j];
    if (sum != target) {
        char buf[220];
        snprintf(buf, sizeof(buf),
            "wrong pair. nums[i]+nums[j]=%d+%d=%d, target=%d (i=%zu j=%zu)",
            nums[i], nums[j], sum, target, i, j);
        expect(0, name, buf);
        return;
    }

    // Check expected indices (we design tests to have a unique pair)
    if (!(i == exp_i && j == exp_j)) {
        char buf[260];
        snprintf(buf, sizeof(buf),
            "wrong indices. expected (%zu,%zu), got (%zu,%zu)",
            exp_i, exp_j, i, j);
        expect(0, name, buf);
        return;
    }

    expect(1, name, "ok");
}

static void benchmark_two_sum(void) {
    printf("\n=== Self-benchmark (CPU time, for self-comparison only) ===\n");

    const size_t n = 2000;          // adjust as desired
    const int reps = 2000;          // adjust as desired (higher = more stable)

    int* nums = (int*)malloc(n * sizeof(int));
    if (!nums) {
        printf("[WARN] benchmark skipped (malloc failed)\n");
        return;
    }

    for (size_t k = 0; k < n; k++) nums[k] = (int)k;

    // Guaranteed solution: i=42, j=1999
    const int target = 42 + 1999;

    size_t out_i = 0, out_j = 0;

    clock_t t0 = clock();
    for (int r = 0; r < reps; r++) {
        (void)two_sum(nums, n, target, &out_i, &out_j);
    }
    clock_t t1 = clock();

    double total = cpu_ms(t0, t1);
    double per_call_us = (total * 1000.0) / reps;

    printf("n=%zu, reps=%d\n", n, reps);
    printf("total_cpu_time=%.2f ms\n", total);
    printf("avg_per_call=%.3f us\n", per_call_us);

    free(nums);
}

int main(void) {
    {
        int nums[] = { 2, 7, 11, 15 };
        run_case("basic_example", nums, 4, 9, 0, 1);
    }
    {
        int nums[] = { 3, 2, 4 };
        run_case("middle_pair", nums, 3, 6, 1, 2);
    }
    {
        int nums[] = { 3, 3 };
        run_case("duplicate_values", nums, 2, 6, 0, 1);
    }
    {
        int nums[] = { -1, -2, -3, -4, -5 };
        run_case("negatives", nums, 5, -8, 2, 4); // -3 + -5
    }
    {
        int nums[] = { 0, 4, 3, 0 };
        run_case("zeros", nums, 4, 0, 0, 3);
    }
    benchmark_two_sum();
    // Summary
    if (fail_count == 0) {
        printf("\nALL TESTS PASSED\n");
        return 0;
    }
    else {
        printf("\n%d TEST(S) FAILED\n", fail_count);
        return 1;
    }
    
}
