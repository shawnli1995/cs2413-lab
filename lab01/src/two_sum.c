#include "two_sum.h"

int two_sum(const int* nums, int n, int target, int* out_i, int* out_j) {

    // TODO: implement Two Sum.
    // Requirements:
    //  - find i < j such that nums[i] + nums[j] == target
    //  - store indices in *out_i and *out_j
    //  - return 1 if found; otherwise return 0
for(int i=0;i<n-1;i++){
	for(int j=i+1;j<=n-1;j++){
      if(nums[i]+nums[j]==target){
		*out_i=i;
		*out_j=j;
		return 1;
	  }
	 }
 }

return 0;
    // //////
    return 0;
}







//think about the time complexity and space complexity of your solution
