#include "Student.h"

//Given an array nums of size n, return the majority element.

//The majority element appears more than ⌊n/2⌋ times.
//You may assume the majority element always exists in the array.

//Example 1:
//Input: nums = [3,2,3]
//Output: 3

//Example 2:
//Input: nums = [2,2,1,1,1,2,2]
//Output: 2


int majorityElement(int* nums, int numsSize) {
     // TODO: implement
     int potential_element = 0;  //majority will start at first index
     int majority_count = 0; //majority counter check
     for (int i = 0; i < numsSize; i++) {
          if (majority_count == 0)
               potential_element = nums[i];

          if (nums[i] == potential_element)
              majority_count++;
          else
               majority_count--;
     }
     return potential_element;

}
