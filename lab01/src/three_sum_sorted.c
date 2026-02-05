#include "three_sum_sorted.h"

int three_sum_zero_sorted_one(const int* nums, int n, int* out_i, int* out_j, int* out_k) {
    
    // implement your code here
    if (!nums || !out_i || !out_j || !out_k || n < 3) return 0;

    for (int i = 0; i < n - 2; i++) {
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {
                *out_i = i;
                *out_j = left;
                *out_k = right;
                return 1;
            } else if (sum < 0) {
                left++;     // need a larger sum
            } else {
                right--;    // need a smaller sum
            }
        }
    }


    return 0;
}
