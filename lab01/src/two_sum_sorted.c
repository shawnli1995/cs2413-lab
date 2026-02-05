#include "two_sum_sorted.h"

int two_sum_sorted(const int* nums, int n, int target, int* out_i, int* out_j) {
    if (!nums || n < 2) return 0;

    int l = 0;      // Left pointer
    int r = n - 1;  // Right pointer

    while (l < r) {
        int sum = nums[l] + nums[r];

        if (sum == target) {
            *out_i = l;
            *out_j = r;
            return 1;
        }
        
        // If sum is too small, increment left to get a larger value.
        // If sum is too big, decrement right to get a smaller value.
        if (sum < target) l++;
        else r--;
    }
    return 0;
}