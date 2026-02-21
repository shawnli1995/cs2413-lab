#include "three_sum_sorted.h"

int three_sum_zero_sorted_one(const int* nums, int n, int* out_i, int* out_j, int* out_k) {
    
    // implement your code here
    if (!nums || !out_i || !out_j || !out_k || n < 3)
        return 0;

    for (int i = 0; i < n-2; i++){

        int l = i+1;
        int r = n-1;

        while (l < r){
            int sum = nums[i] + nums[l] + nums[r];

            if (sum == 0){

                *out_i = i;
                *out_j = l;
                *out_k = r;

                return 1;
            } else if (sum < 0){

                l++;

            } else{

                r--;

            }

        }
    }

    return 0;
}
