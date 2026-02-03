#include "three_sum_sorted.h"

int three_sum_zero_sorted_one(const int* nums, int n, int* out_i, int* out_j, int* out_k) {
    
    for (int i = 0; i < n - 2; i++){
        int low = i + 1, high = n - 1;
        while (low < high){
            int sum = nums[i] + nums[low] + nums[high];
            if (sum == 0){
                *out_i = i;
                *out_j = low;
                *out_k = high;
                return 1;
            }
            else if (sum > 0){
                high--;
            }
            else {
                low++;
            }
        }
    }

    return 0;
}
