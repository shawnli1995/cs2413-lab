#include "three_sum_sorted.h"

int three_sum_zero_sorted_one(const int* nums, int n, int* out_i, int* out_j, int* out_k) {
    
   int i = 0;
   int j = 0;
   int k = 0;

   if(nums[i] + nums[j] + nums[k] != 0) {
        if(nums[i] + nums[j] + nums[k] < 0) {
            while(nums[i] + nums[j] + nums[k] < 0) {
                i++;
            }
            if(nums[i] + nums[j] + nums[k] == 0) {
                *out_i = i;
                *out_j = j;
                *out_k = k;
                return 1;
            } else {
                while(nums[i] + nums[j] + nums[k] < 0) {
                    j++;
                }
                if(nums[i] + nums[j] + nums[k] == 0) {
                    *out_i = i;
                    *out_j = j;
                    *out_k = k;
                    return 1;
                } else {
                    while(nums[i] + nums[j] + nums[k] < 0) {
                        k++;
                    }
                    if(nums[i] + nums[j] + nums[k] == 0) {
                        *out_i = i;
                        *out_j = j;
                        *out_k = k;
                        return 1;
                    } else {
                        return 0;
                    }
                }
            }
        }
   }

    return 0;
}
