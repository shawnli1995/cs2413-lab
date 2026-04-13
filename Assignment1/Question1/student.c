#include "student.h"

//You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n:
//nums1 has length m + n
//The first m values in nums1 are real elements
//The last n values in nums1 are placeholders (0)
//nums2 has length n
//Goal: Merge nums2 into nums1 so that nums1 becomes one sorted array.
//Return: Nothing (modify nums1 in-place).

//Example:
//Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
//Output: nums1 = [1,2,2,3,5,6]
//Explanation: The arrays we are merging are [1,2,3] and [2,5,6].

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    (void)nums1Size;
    (void)nums2Size;

 // TODO: implement
    int final;
    int n1= m-1;
    int n2= n-1;
    
    for(final=m+n-1; n2>=0; final--){
        if(n1>=0 && nums1[n1]>nums2[n2]){
            nums1[final]=nums1[n1];
            n1--;
        }
        else {
            nums1[final]=nums2[n2];
            n2--;
            }
        }
}
