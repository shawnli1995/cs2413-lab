#include "Student.h"
#include <stdio.h>

static int fails = 0;

static void expect_bool(const char *name, bool got, bool want) {
    if (got != want) {
        fails++;
        printf("[FAIL] %s: got %s, want %s\n",
               name,
               got ? "true" : "false",
               want ? "true" : "false");
    } else {
        printf("[PASS] %s\n", name);
    }
}

int run_tests(void) {
    // Basic
    expect_bool("empty", isValid(""), true);
    expect_bool("single_open", isValid("("), false);
    expect_bool("single_close", isValid(")"), false);

    // Simple valid
    expect_bool("paren_pair", isValid("()"), true);
    expect_bool("bracket_pair", isValid("[]"), true);
    expect_bool("brace_pair", isValid("{}"), true);

    // Mixed valid
    expect_bool("nested_1", isValid("([])"), true);
    expect_bool("nested_2", isValid("{[()]}"), true);
    expect_bool("concat", isValid("()[]{}"), true);
    expect_bool("leetcode_example_valid", isValid("()[]{}"), true);

    // Invalid order / mismatch
    expect_bool("mismatch_1", isValid("(]"), false);
    expect_bool("mismatch_2", isValid("([)]"), false);
    expect_bool("wrong_close_type", isValid("{]"), false);

    // Closing too early
    expect_bool("close_first", isValid("]"), false);
    expect_bool("early_close", isValid("())"), false);

    // Leftover opens
    expect_bool("leftover_open", isValid("((("), false);
    expect_bool("leftover_open_2", isValid("(()"), false);
    expect_bool("leftover_open_3", isValid("{[("), false);

    // Longer
    expect_bool("long_valid",
                isValid("({[]})({[]})({[]})"),
                true);

    // Stress-ish (still small)
    expect_bool("many_nested_valid",
                isValid("(((((([[[[[{{{{{}}}}}]]]]]))))))"),
                true);

    printf("\nTotal fails: %d\n", fails);
    return fails;
}
