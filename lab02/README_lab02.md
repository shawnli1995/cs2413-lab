## README — Lab: Stacks and Queues

This lab contains two practice problems:

- **Question 1:** Valid Parentheses 
- **Question 2:** Design Circular Queue 

You will implement the required function(s) in `Student.c` for each question and run the provided tests.

---

# General Setup

### Folder structure (expected)
```
lab02/
├── Makefile
├── Question1/
│   ├── Student.h
│   ├── Student.c     //edit this one
│   ├── tests.c
│   └── runner.c
└── Question2/
    ├── Student.h
    ├── Student.c    //edit this one
    ├── tests.c
    └── runner.c
```

### Compile + Run
From the **lab02/** folder (where the `Makefile` is), run:

```bash
make run1
make run2
```

To remove compiled binaries:

```bash
make clean
```

---

# Question 1 — Valid Parentheses (Stack)

## Problem
Given a string `s` containing only the characters:

- `'(' , ')' , '{' , '}' , '[' , ']'`

Return `true` if the string is **valid**, otherwise return `false`.

A string is valid if:
1. Open brackets must be closed by the **same type** of brackets.
2. Open brackets must be closed in the **correct order**.
3. Every close bracket has a corresponding open bracket.

## What you implement
File: **`Question1/Student.c`**

Implement:
```c
bool isValid(const char *s);
```

## Recommended approach
Use a **stack**:
- Push opening brackets `(`, `[`, `{`
- When you see a closing bracket:
  - the stack must not be empty
  - the top must match the correct opening bracket
  - pop the stack
- At the end, the stack must be empty

## Examples
- `s = "()"` → `true`
- `s = "()[]{}"` → `true`
- `s = "(]"` → `false`
- `s = "([)]"` → `false`
- `s = "{[]}"` → `true`
- `s = ""` → `true`

## Run tests
```bash
make run1
```

---

# Question 2 — Design Circular Queue (Ring Buffer)

## Problem
Design a circular queue with fixed capacity `k`. Implement enqueue/dequeue and query operations.

Operations to support:
- `enQueue(value)` → insert an element
- `deQueue()` → delete an element
- `Front()` → get the front element
- `Rear()` → get the last element
- `isEmpty()` → whether queue is empty
- `isFull()` → whether queue is full

Return rules:
- `Front()` and `Rear()` should return **-1** if the queue is empty.
- `enQueue()` returns `false` if the queue is full.
- `deQueue()` returns `false` if the queue is empty.

## What you implement
File: **`Question2/Student.c`**

Implement the functions declared in `Question2/Student.h`:
- `myCircularQueueCreate`
- `myCircularQueueEnQueue`
- `myCircularQueueDeQueue`
- `myCircularQueueFront`
- `myCircularQueueRear`
- `myCircularQueueIsEmpty`
- `myCircularQueueIsFull`
- `myCircularQueueFree`

## Recommended design (important)
Use these fields and invariants (simple + avoids ambiguity):
- `size`: current number of elements
- empty ⇔ `size == 0`
- full ⇔ `size == capacity`
- `head`: index of front element
- `tail`: index of next insertion position
- wrap with modulo: `(idx + 1) % capacity`

## Example (k = 3)
Sequence:
- `enQueue(1)` → true
- `enQueue(2)` → true
- `enQueue(3)` → true
- `enQueue(4)` → false (full)
- `Rear()` → 3
- `isFull()` → true
- `deQueue()` → true
- `enQueue(4)` → true
- `Rear()` → 4
- `Front()` → 2

## Run tests
```bash
make run2
```

---

# Tips and Common Mistakes

### Question 1 (Stack)
- Forgetting to check stack empty before popping
- Not matching bracket types correctly
- Returning true even if stack still has unclosed opens at the end

### Question 2 (Circular Queue)
- Confusing what `tail` means (should be “next write position”)
- Off-by-one errors in modulo arithmetic
- Using `head == tail` without tracking `size` (ambiguous: empty vs full)
- Not freeing allocated memory in `myCircularQueueFree`
