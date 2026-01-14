#include "two_sum.h"

int two_sum(const int* nums, size_t n, int target, size_t* out_i, size_t* out_j) {
    if (!nums || !out_i || !out_j || n < 2) {
        return 0;
    }

    for (size_t i = 0; i < n; i++) {
        for (size_t j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                *out_i = i;
                *out_j = j;
                return 1;
            }
        }
    }

    return 0;  // no solution found
}
