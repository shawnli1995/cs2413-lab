#ifndef TWO_SUM_H
#define TWO_SUM_H

#include <stddef.h>

/*
 * two_sum
 * Returns 1 if a solution is found and writes indices to out_i and out_j.
 * Returns 0 otherwise.
 *
 * Requirements:
 * - If a solution exists, ensure *out_i < *out_j
 * - Do not use the same element twice
 */
int two_sum(const int* nums, int n, int target, int* out_i, int* out_j);

#endif
