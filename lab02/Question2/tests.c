#include "Student.h"
#include <stdio.h>

static int fails = 0;

static void expect_bool(const char *name, bool got, bool want) {
    if (got != want) {
        fails++;
        printf("[FAIL] %s: got %s, want %s\n", name,
               got ? "true" : "false", want ? "true" : "false");
    } else {
        printf("[PASS] %s\n", name);
    }
}

static void expect_int(const char *name, int got, int want) {
    if (got != want) {
        fails++;
        printf("[FAIL] %s: got %d, want %d\n", name, got, want);
    } else {
        printf("[PASS] %s\n", name);
    }
}

int run_tests(void) {
    // Classic example sequence (k=3)
    MyCircularQueue *q = myCircularQueueCreate(3);

    expect_bool("enq1", myCircularQueueEnQueue(q, 1), true);
    expect_bool("enq2", myCircularQueueEnQueue(q, 2), true);
    expect_bool("enq3", myCircularQueueEnQueue(q, 3), true);

    expect_bool("enq4_should_fail_full", myCircularQueueEnQueue(q, 4), false);
    expect_int("rear_is_3", myCircularQueueRear(q), 3);

    expect_bool("isFull_true", myCircularQueueIsFull(q), true);

    expect_bool("deq_ok", myCircularQueueDeQueue(q), true);
    expect_bool("enq4_ok_after_deq", myCircularQueueEnQueue(q, 4), true);

    expect_int("rear_is_4", myCircularQueueRear(q), 4);
    expect_int("front_is_2", myCircularQueueFront(q), 2);

    myCircularQueueFree(q);

    // Wrap-around behavior
    q = myCircularQueueCreate(2);
    expect_bool("wrap_enq10", myCircularQueueEnQueue(q, 10), true);
    expect_bool("wrap_enq20", myCircularQueueEnQueue(q, 20), true);
    expect_bool("wrap_full", myCircularQueueIsFull(q), true);

    expect_bool("wrap_deq", myCircularQueueDeQueue(q), true); // removes 10
    expect_int("wrap_front20", myCircularQueueFront(q), 20);

    expect_bool("wrap_enq30", myCircularQueueEnQueue(q, 30), true); // should wrap to index 0
    expect_int("wrap_rear30", myCircularQueueRear(q), 30);
    expect_int("wrap_front20_again", myCircularQueueFront(q), 20);

    myCircularQueueFree(q);

    // Empty edge cases
    q = myCircularQueueCreate(1);
    expect_int("empty_front_-1", myCircularQueueFront(q), -1);
    expect_int("empty_rear_-1", myCircularQueueRear(q), -1);
    expect_bool("empty_deq_false", myCircularQueueDeQueue(q), false);
    expect_bool("empty_isEmpty_true", myCircularQueueIsEmpty(q), true);

    expect_bool("k1_enq", myCircularQueueEnQueue(q, 7), true);
    expect_bool("k1_full_true", myCircularQueueIsFull(q), true);
    expect_bool("k1_enq_fail", myCircularQueueEnQueue(q, 8), false);
    expect_int("k1_front_7", myCircularQueueFront(q), 7);
    expect_int("k1_rear_7", myCircularQueueRear(q), 7);

    expect_bool("k1_deq", myCircularQueueDeQueue(q), true);
    expect_bool("k1_empty_true", myCircularQueueIsEmpty(q), true);

    myCircularQueueFree(q);

    printf("\nTotal fails: %d\n", fails);
    return fails;
}
