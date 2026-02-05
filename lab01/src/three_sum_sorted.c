#include "three_sum_sorted.h"

int three_sum_zero_sorted_one(const int* nums, int n, int* out_i, int* out_j, int* out_k) {
    if (!nums || n < 3) return 0;

    for (int i = 0; i < n - 2; i++) {
        int l = i + 1; // Left pointer starts after i
        int r = n - 1; // Right pointer starts at the end
        
        // We need: nums[l] + nums[r] == 0 - nums[i]
        int target = -nums[i];

        while (l < r) {
            int sum = nums[l] + nums[r];

            if (sum == target) {
                *out_i = i;
                *out_j = l;
                *out_k = r;
                return 1; // Found valid triplet
            }

            if (sum < target) l++;
            else r--;
        }
    }
    return 0;
}