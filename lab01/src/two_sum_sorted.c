#include "two_sum_sorted.h"

int two_sum_sorted(const int* nums, int n, int target, int* out_i, int* out_j) {
    if (!nums || !out_i || !out_j || n < 2) return 0;

    // TODO: implement rwo sum solution for sorted arrays.
    for(int i = 0; i<n;){
        for(int j = n-1; j<n;){
            if (nums[i] + nums[j]<target)
                i++;
            else if(nums[i] + nums[j] > target)
                j--;
            else{
                *out_i = i;
                *out_j = j;
                return 1;
            }
        }

    }

    return 0;
}
// think about the time complexity and space complexity of your solution

