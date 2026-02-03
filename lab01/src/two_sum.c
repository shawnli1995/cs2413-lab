#include "two_sum.h"

int two_sum(const int* nums, int n, int target, int* out_i, int* out_j) {

    
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            int sum = nums[i] + nums[j];
            if (sum == target){
                *out_i = i;
                *out_j = j;
                return 1;
            }
        }
    }

    return 0;
}

//think about the time complexity and space complexity of your solution
