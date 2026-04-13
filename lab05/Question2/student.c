/*
Question 2: Kth Largest Element in an Array

Description:
Given an integer array nums and an integer k, return the kth largest
element in the array.

Note that it is the kth largest element in sorted order, not the kth
distinct element.

For this lab, you should solve the problem using a heap-based idea.

Function:
int findKthLargest(int* nums, int numsSize, int k);

Notes:
- You may assume 1 <= k <= numsSize.
- Repeated values still count.
- A min-heap of size k is a good way to solve this efficiently.

Example 1:
Input:  nums = [3, 2, 1, 5, 6, 4], k = 2
Output: 5

Example 2:
Input:  nums = [3, 2, 3, 1, 2, 4, 5, 5, 6], k = 4
Output: 4

Hint:
Keep only the k largest elements seen so far in a min-heap.
The root of that heap will be the kth largest element.
*/

#include <stdlib.h>

/*
Optional helper function declarations.

You may use them, modify them, or remove them if you prefer your own design.
*/
static void swap(int* a, int* b);
static void heapifyUp(int* heap, int index);
static void heapifyDown(int* heap, int size, int index);

/*
Return the kth largest element in nums.
*/
int findKthLargest(int* nums, int numsSize, int k) {
    /* Write your code here*/
    int* heap = (int*)malloc(k * sizeof(int));
    int size = 0;

    for (int i = 0; i < numsSize; i++) {
        heap[size] = nums[i];
        heapifyUp(heap, size);
        size++;

        if (size > k) {
            heap[0] = heap[size - 1];
            size--;
            heapifyDown(heap, size, 0);
        }
    }
    int result = heap[0];
    free(heap);
    return result;
}

/*
Optional helper: swap two integers.
*/
static void swap(int* a, int* b) {
    /* Write your code here if you use this helper */
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
Optional helper: restore min-heap order from a node upward.
*/
static void heapifyUp(int* heap, int index) {
    /* Write your code here if you use this helper */
    while (index > 0) {

        int parent = (index - 1) / 2;

        if (heap[parent] <= heap[index])
            break;

        swap(&heap[parent], &heap[index]);
        index = parent;
    }
}

/*
Optional helper: restore min-heap order from a node downward.
*/
static void heapifyDown(int* heap, int size, int index) {
    /* Write your code here if you use this helper */
    while (1) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;

        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == index)
            break;

        swap(&heap[index], &heap[smallest]);
        index = smallest;
    }
}