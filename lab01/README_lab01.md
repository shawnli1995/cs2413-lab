# Lab 01: Array Practice (Two Sum + Extra Practice)

In this lab, you will practice writing C functions that work with arrays and indices.
You will implement small search problems and verify your code using the provided tests.

**Where you write code:** `src/`  
**How you check your work:** run tests in `tests/` using `make`

---

## Folder structure

```
lab01/
├── Makefile
├── src/
│   ├── two_sum.h
│   ├── two_sum.c                 <-- YOU EDIT (required)
│   ├── two_sum_sorted.h          
│   ├── two_sum_sorted.c          <-- YOU EDIT (extra)
│   ├── three_sum_sorted.h        
│   └── three_sum_sorted.c        <-- YOU EDIT (extra)
└── tests/
    ├── test_two_sum.c
    ├── test_two_sum_sorted.c     
    └── test_three_sum_sorted.c   
```

**Important rule:** Do **not** edit files under `tests/` unless your instructor tells you to.

---

## How to run

From the lab root folder:

### Run required Two Sum tests
```bash
make run
```

### Optional: run without benchmark output (if enabled)
```bash
make run_nobench
```

### Clean compiled output
```bash
make clean
```

---

# Part 1 (Required): Two Sum — Unsorted Array

## Problem:
You are given a list of integers and a target number.
Find **two different positions** in the array such that the two numbers add up to the target.

Example:
- Array: `[2, 7, 11, 15]`
- Target: `9`
- One answer: indices `(0, 1)` because `2 + 7 = 9`

If there are multiple correct answers, returning **any one** correct pair is acceptable.

---

## Function you must implement

```c
int two_sum(const int* nums, int n, int target, int* out_i, int* out_j);
```

### What each parameter means
- `nums`  
  Pointer to the first element of the integer array.  
  It is `const`, so you must **not modify** the array.

- `n`  
  Number of elements in `nums`. Valid indices are `0` to `n-1`.

- `target`  
  The value you want `nums[i] + nums[j]` to equal.

- `out_i`, `out_j`  
  Output parameters (pointers). If you find a solution, store indices here:
  - `*out_i = i;`
  - `*out_j = j;`

### Return value
- Return `1` if you found indices `i` and `j` such that:
  - `0 <= i < j < n`
  - `nums[i] + nums[j] == target`
- Return `0` if no solution exists or input is invalid (for example, `n < 2`).

---

# Extra Practice A: Two Sum — Sorted Array (Two Pointers)

## Problem:
Same as Two Sum, but the array is already **sorted** (non-decreasing order).
Because it is sorted, you can solve it faster using **two pointers**.

Example:
- Sorted array: `[1, 2, 4, 6, 10]`
- Target: `8`
- One answer: indices `(1, 3)` because `2 + 6 = 8`

---

## Function to implement (in two_sum_sorted.c)


```c
int two_sum_sorted(const int* nums, int n, int target, int* out_i, int* out_j);
```

### Parameters and return value
Same meaning as the unsorted version:
- `nums`: sorted integer array (do not modify)
- `n`: number of elements
- `target`: desired sum
- `out_i`, `out_j`: store the found indices
- return `1` if found, otherwise return `0`

### Hint (two pointers)
- Start `i = 0` and `j = n - 1`
- If `nums[i] + nums[j]` is too small → move `i` right (`i++`)
- If too large → move `j` left (`j--`)

### Run 
```bash
make run_sorted
```

---

# Extra Practice B: Three Sum — Sorted Array 

## Problem:
You are given a **sorted** array.
Find **any three different positions** `i < j < k` such that:

- `nums[i] + nums[j] + nums[k] == 0`

You only need to find **one** valid triplet.

Example:
- Sorted array: `[-4, -1, -1, 0, 1, 2]`
- One answer: indices `(1, 3, 4)` because `-1 + 0 + 1 = 0`

---

## Function to implement (in three_sum_sorted.c)

```c
int three_sum_zero_sorted_one(const int* nums, int n, int* out_i, int* out_j, int* out_k);
```

### What each parameter means
- `nums`  
  Sorted integer array (non-decreasing). Do not modify it.

- `n`  
  Number of elements in `nums`. Valid indices are `0..n-1`.

- `out_i`, `out_j`, `out_k`  
  Output parameters. If a valid triplet is found, store indices here:
  - `*out_i = i;`
  - `*out_j = j;`
  - `*out_k = k;`

### Return value
- Return `1` if you found indices `i < j < k` such that the sum is 0
- Return `0` if no such triplet exists or input is invalid (`n < 3`)

### Hint (O(n^2) approach)
- Fix `i` from left to right
- For each `i`, use two pointers `L = i + 1` and `R = n - 1`
- Move pointers based on whether the sum is too small or too large

### Run 
```bash
make run_three_sorted
```

---

## Common mistakes
- Forgetting to enforce `i < j` (Two Sum) or `i < j < k` (Three Sum)
- Returning `1` without writing output indices
- Not handling small arrays (`n < 2` or `n < 3`)
- Modifying `nums` even though it is `const`

---

## Submission
Only edit files in `src/` unless your instructor tells you otherwise.
Commit and push your changes according to the course submission instructions.
