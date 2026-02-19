#include <stdio.h>

int run_tests(void);

int main(void) {
    int fails = run_tests();
    if (fails == 0) {
        printf("All tests passed.\n");
        return 0;
    } else {
        printf("Some tests failed.\n");
        return 1;
    }
}
