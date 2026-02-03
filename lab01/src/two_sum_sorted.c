#include "two_sum_sorted.h"

int two_sum_sorted(const int* nums, int n, int target, int* out_i, int* out_j) {
    if (!nums || !out_i || !out_j || n < 2) return 0;

    int low = 0, high = n - 1;
    
    while (low < high){
        int sum = nums[low] + nums[high];
        if (sum == target){
            *out_i = low;
            *out_j = high;
            return 1;
        }
        else if (sum > target){
            high--;
        }
        else {
            low++;
        }
    }
    
    return 0;
}
// think about the time complexity and space complexity of your solution

