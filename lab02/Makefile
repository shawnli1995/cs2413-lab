CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror -O2

Q1_BIN = q1_run
Q2_BIN = q2_run


.PHONY: all run1 run2 clean

all: run3


run1: $(Q1_BIN)
	./$(Q1_BIN)

run2: $(Q2_BIN)
	./$(Q2_BIN)




clean:
	rm -f $(Q1_BIN) $(Q2_BIN)


$(Q1_BIN): Question1/runner.c Question1/tests.c Question1/Student.c Question1/Student.h
	$(CC) $(CFLAGS) Question1/runner.c Question1/tests.c Question1/Student.c -o $(Q1_BIN)

$(Q2_BIN): Question2/runner.c Question2/tests.c Question2/Student.c Question2/Student.h
	$(CC) $(CFLAGS) Question2/runner.c Question2/tests.c Question2/Student.c -o $(Q2_BIN)
