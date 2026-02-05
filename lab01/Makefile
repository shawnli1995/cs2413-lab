CC ?= cc
CFLAGS = -std=c11 -Wall -Wextra -O2 -I./src

BIN_DIR = bin
TARGET  = $(BIN_DIR)/two_sum_run

SRC  = src/two_sum.c
MAIN = tests/test_two_sum.c

.PHONY: all test run run_nobench clean

all: $(TARGET)

# Default build: benchmark ON
$(TARGET): $(SRC) $(MAIN) src/two_sum.h
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -DBENCHMARK=1 $(SRC) $(MAIN) -o $(TARGET)

# make run -> benchmark ON
run: $(TARGET)
	./$(TARGET)

# make run_nobench -> benchmark OFF
run_nobench:
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -DBENCHMARK=0 $(SRC) $(MAIN) -o $(TARGET)
	./$(TARGET)

# make test -> default (no benchmark)
test: run_nobench

clean:
	rm -rf $(BIN_DIR)


SORTED_SRC  = src/two_sum_sorted.c
SORTED_MAIN = tests/test_two_sum_sorted.c
SORTED_BIN  = $(BIN_DIR)/two_sum_sorted_run

$(SORTED_BIN): $(SORTED_SRC) $(SORTED_MAIN) src/two_sum_sorted.h
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(SORTED_SRC) $(SORTED_MAIN) -o $(SORTED_BIN)

run_sorted: $(SORTED_BIN)
	./$(SORTED_BIN)

THREE_SORTED_SRC  = src/three_sum_sorted.c
THREE_SORTED_MAIN = tests/test_three_sum_sorted.c
THREE_SORTED_BIN  = $(BIN_DIR)/three_sum_sorted_run

$(THREE_SORTED_BIN): $(THREE_SORTED_SRC) $(THREE_SORTED_MAIN) src/three_sum_sorted.h
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(THREE_SORTED_SRC) $(THREE_SORTED_MAIN) -o $(THREE_SORTED_BIN)

run_three_sorted: $(THREE_SORTED_BIN)
	./$(THREE_SORTED_BIN)
