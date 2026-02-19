# Assignment 1 

This assignment contains three problems implemented in **C**.  
You will use the same GitHub repository workflow we used in lab: update your fork, pull, edit **one C file per question**, run tests with `make`, and submit your GitHub repo link on Canvas.

---

## Repository structure

```
Assignment1/
  Makefile
  Readme_assignment1.md

  Question1/
    Student.c
    Student.h
    test.c
    runner.c

  Question2/
    Student.c
    Student.h
    test.c
    runner.c

  Question3/
    Student.c
    Student.h
    test.c
    runner.c
```

---

## Problems

### Question 1 — Merge Sorted Array
You are given two integer arrays `nums1` and `nums2`, sorted in non-decreasing order, and two integers `m` and `n`:

- `nums1` has length `m + n`
- The first `m` values in `nums1` are real elements
- The last `n` values in `nums1` are placeholders (0)
- `nums2` has length `n`

**Goal:** Merge `nums2` into `nums1` so that `nums1` becomes one sorted array.  
**Return:** Nothing (modify `nums1` in-place).

Example:<br>
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3<br>
Output: [1,2,2,3,5,6]<br>
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].<br>

---

### Question 2 — Majority Element
Given an array `nums` of size `n`, return the **majority element**.

The majority element appears **more than** `⌊n/2⌋` times.  
You may assume the majority element always exists in the array.

Example 1:<br>
Input: nums = [3,2,3]<br>
Output: 3<br>

Example 2:<br>
Input: nums = [2,2,1,1,1,2,2]<br>
Output: 2<br>

---

### Question 3 — Plus One 
You are given a large integer represented as an integer array `digits`, where:

- `digits[i]` is the i-th digit of the integer
- digits are ordered from most significant to least significant
- there are no leading 0s (except the number 0 itself in some of our tests)

**Goal:** Add 1 to the number and return the resulting digits array.

Example 1:<br>
Input: digits = [4,3,2,1]<br>
Output: [4,3,2,2]<br>
Explanation: The array represents the integer 4321.<br>
Incrementing by one gives 4321 + 1 = 4322.<br>
Thus, the result should be [4,3,2,2].<br>

Example 2:<br>
Input: digits = [9]<br>
Output: [1,0]<br>
Explanation: The array represents the integer 9.<br>
Incrementing by one gives 9 + 1 = 10.<br>
Thus, the result should be [1,0].<br>

Return value (int*): the output digits array.<br>
Output parameter (returnSize): set *returnSize to the number of digits in the returned array.<br>

---

## What you need to edit

Only edit these files:

- `Question1/Student.c`
- `Question2/Student.c`
- `Question3/Student.c`

Do **NOT** edit:
- `test.c`, `runner.c`, `Student.h`, or the `Makefile`

(Grading and the provided tests assume these files keep their original structure.)

---

## How to run tests

From the assignment root folder (the folder containing the `Makefile`), run:

```bash
make run1   # Question 1 tests
make run2   # Question 2 tests
make run3   # Question 3 tests
```

Each test run prints:
- PASS/FAIL for each test case
- a summary at the end

---

## Update your repo (same as lab)

### 1) Sync your fork on GitHub (web)
1. Go to **your forked repository** on GitHub.
2. Click **Sync fork** to update your fork with the newest assignment code.

### 2) Pull the latest code on your computer (terminal)
Go to your local repo folder (the same one you used in lab), then run:

```bash
git pull
```

Make sure you are inside the correct folder (the one that contains the `Makefile`).

---

## Submission

### Upload your updated code to GitHub (two options)

#### Option A (recommended): push with Git commands
After you finish (and your tests pass):

```bash
git add Question1/Student.c Question2/Student.c Question3/Student.c
git commit -m "Finish Assignment 1"
git push
```

#### Option B: upload/edit files on the GitHub website
1. Open your forked repository on GitHub.
2. Navigate to the file you updated (example: `Question1/Student.c`).
3. Click the **pencil icon** (Edit) OR use **Add file → Upload files**.
4. Scroll down and **Commit changes**.

> If you upload via GitHub website, you should still run tests locally (`make run1/run2/run3`) to ensure your code works.

### Canvas submission
Submit your **GitHub repository link** (your fork) on Canvas.

Example link format:
- `https://github.com/<your-username>/<repo-name>`

---

# Guidance for Question 3 (Plus One) 

### Function signature 
```c
int* plusOne(int* digits, int digitsSize, int* returnSize);
```

### What you MUST do
1. Compute the result of adding 1 to the number.
2. Allocate a **new int array** using `malloc`.
3. Store the output digits into the new array.
4. Set `*returnSize` to the output length.
5. Return the pointer to the allocated array.
6. The test code will call `free()` on your returned pointer.

---

## Why you must allocate memory (malloc)
In C, you cannot safely return a local array like this:

```c
int out[100];     // ❌ wrong
return out;       // out disappears after function returns
```

Local arrays live on the stack and become invalid after the function ends.

So you must do:

```c
int* out = (int*)malloc(outputSize * sizeof(int));  // ✅ correct
```

---











