#include "two_sum_sorted.h"

int two_sum_sorted(const int* nums, int n, int target, int* out_i, int* out_j) {
    if (!nums || !out_i || !out_j || n < 2) return 0;

    int left = 0;
    int right = n - 1;

    while (left < right) {
        int sum = nums[left] + nums[right];

        if (sum == target) {
            *out_i = left;
            *out_j = right;
            return 1;
        } else if (sum < target) {
            left++;      // need a larger sum
        } else {
            right--;     // need a smaller sum
        }
    }
    // TODO: implement rwo sum solution for sorted arrays.

    return 0;
}
// think about the time complexity and space complexity of your solution

