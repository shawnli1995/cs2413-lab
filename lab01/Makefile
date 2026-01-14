CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -Werror -O2 -I./src

TEST_BIN=bin/test_two_sum

all: test

test: $(TEST_BIN)
	./$(TEST_BIN)

$(TEST_BIN): src/two_sum.c tests/test_two_sum.c src/two_sum.h
	mkdir -p bin
	$(CC) $(CFLAGS) src/two_sum.c tests/test_two_sum.c -o $(TEST_BIN)

clean:
	rm -rf bin

.PHONY: all test clean
