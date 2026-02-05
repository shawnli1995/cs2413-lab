#include <stdio.h>
#include "three_sum_sorted.h"

static int fails = 0;

static void expect(int cond, const char* name, const char* msg) {
    if (!cond) {
        printf("[FAIL] %s: %s\n", name, msg);
        fails++;
    } else {
        printf("[PASS] %s\n", name);
    }
}

static void run_case_any(const char* name, const int* nums, int n, int expect_found) {
    int i = -1, j = -1, k = -1;
    int ok = three_sum_zero_sorted_one(nums, n, &i, &j, &k);

    if (!expect_found) {
        expect(ok == 0, name, "expected no solution but got return=1");
        return;
    }

    if (!ok) {
        expect(0, name, "expected a solution but got return=0");
        return;
    }

    if (!(0 <= i && i < j && j < k && k < n)) {
        expect(0, name, "indices must satisfy 0 <= i < j < k < n");
        return;
    }

    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[k];
    expect(sum == 0, name, "returned indices do not sum to 0");
}

int main(void) {
    {
        // sorted classic: solutions exist
        int nums[] = {-4, -1, -1, 0, 1, 2};
        run_case_any("classic_sorted_any", nums, 6, 1);
    }
    {
        // all zeros: solution exists
        int nums[] = {0, 0, 0, 0};
        run_case_any("all_zeros_any", nums, 4, 1);
    }
    {
        // no solution
        int nums[] = {-5, -4, -3, -2, -1};
        run_case_any("no_solution_any", nums, 5, 0);
    }
    {
        // small n
        int nums[] = {0, 0};
        run_case_any("n_too_small", nums, 2, 0);
    }

    if (fails == 0) {
        printf("ALL THREE-SUM-SORTED TESTS PASSED\n");
        return 0;
    }
    printf("%d TEST(S) FAILED\n", fails);
    return 1;
}
