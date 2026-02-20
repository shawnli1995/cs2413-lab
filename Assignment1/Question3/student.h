#ifndef QUESTION3_STUDENT_H
#define QUESTION3_STUDENT_H

#include <stddef.h>

/*
 * Q1: Plus One
 *
 * You are given a large integer represented as an integer array digits,
 * where digits[i] is the i-th digit of the integer.
 *
 * Increment the large integer by one and return the resulting array of digits.
 *
 * LeetCode-style requirements:
 * - Return a newly allocated int array (malloc).
 * - Set *returnSize to the length of the returned array.
 * - The caller will free the returned array.
 */
int* plusOne(int* digits, int digitsSize, int* returnSize);

#endif
