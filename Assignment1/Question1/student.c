#include "Student.h"

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


 // TODO: implement
int last_nums1 = (m + n) - n - 1; // last defined element of nums1
int last_nums2 = nums2Size - 1;  //last define element of nums2
int write = nums1Size - 1;      //index position we are going to write in
// write backwards
while(last_nums2 >= 0){ //finish once last element in second array is addressed
	if (last_nums1 >= 0 && nums1[last_nums1] > nums2[last_nums2]){ //sorting
      nums1[write] = nums1[last_nums1];
      last_nums1 = last_nums1 - 1;

	} else {
     nums1[write] = nums2[last_nums2];
	 last_nums2 = last_nums2 - 1;
     }
     write--;  //decrementing since we are appending backwards
}

}
