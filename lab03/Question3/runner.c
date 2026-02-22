// Question3/runner.c
// ------------------------------------------------------------
// Runner for Lab03 Question3
// ------------------------------------------------------------

#include <stdio.h>

int run_tests(void);

int main(void) {
    int code = run_tests();
    if (code == 0) printf("All tests passed.\n");
    else printf("Some tests failed.\n");
    return code;
}