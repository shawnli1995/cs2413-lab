#include <stdio.h>
#include "two_sum_sorted.h"

static int fails = 0;

static void expect(int cond, const char* name) {
    if (!cond) { printf("[FAIL] %s\n", name); fails++; }
    else       { printf("[PASS] %s\n", name); }
}

static void run_case_any(const char* name, const int* nums, int n, int target, int expect_found) {
    int i = -1, j = -1;
    int ok = two_sum_sorted(nums, n, target, &i, &j);

    if (!expect_found) {
        expect(ok == 0, name);
        return;
    }

    if (!ok) { expect(0, name); return; }
    if (!(0 <= i && i < j && j < n)) { expect(0, name); return; }
    long long sum = (long long)nums[i] + (long long)nums[j];
    expect(sum == target, name);
}

int main(void) {
    { int a[] = {2, 7, 11, 15}; run_case_any("sorted_basic", a, 4, 9, 1); }
    { int a[] = {1, 2, 3, 4, 6}; run_case_any("sorted_endpoints", a, 5, 7, 1); }
    { int a[] = {-5, -2, 0, 3, 10}; run_case_any("sorted_negative", a, 5, 8, 1); }
    { int a[] = {1, 1, 1, 2, 3}; run_case_any("sorted_duplicates", a, 5, 4, 1); }
    { int a[] = {1, 2, 3, 4}; run_case_any("sorted_no_solution", a, 4, 100, 0); }
    { int a[] = {5}; run_case_any("sorted_small_n", a, 1, 5, 0); }

    if (fails == 0) { printf("ALL SORTED TESTS PASSED\n"); return 0; }
    printf("%d TEST(S) FAILED\n", fails);
    return 1;
}
