#include "three_sum_sorted.h"

int three_sum_zero_sorted_one(const int* nums, int n, int* out_i, int* out_j, int* out_k) {
    
    // implement your code here
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k<n; k++){
                if(nums[i] + nums[j] + nums[k] == 0 && i<j && j<k){
                    *out_k = k;
                    *out_i = i;
                    *out_j = j;
                    return 1;
                }
            }
        }
    }

    return 0;
}
