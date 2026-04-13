#include "three_sum_sorted.h"

int three_sum_zero_sorted_one(const int* nums, int n, int* out_i, int* out_j, int* out_k) {
    
    // implement your code here
    if(!nums || !out_i || !out_j || n<3){
        return 0;
    }
    int a[10];
    int i, j, k;
    for (i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            for(k=j+1; k<n; k++){
                if(nums[i]+nums[j]+nums[k]==0){
                    *out_i=i;
                    *out_j=j;
                    *out_k=k;
                    return 1;
                }
            }
        }
    }

    return 0;
}
