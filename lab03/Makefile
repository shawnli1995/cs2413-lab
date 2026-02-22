CC = gcc
CFLAGS = -std=c11 -Wall -Wextra  -O2

Q1_BIN = q1_run
Q2_BIN = q2_run
Q3_BIN = q3_run
Q4_BIN = q4_run

.PHONY: all run1 run2 run3 run4 clean

all: run1

run1: clean $(Q1_BIN)
	./$(Q1_BIN)

run2: clean $(Q2_BIN)
	./$(Q2_BIN)

run3: clean $(Q3_BIN)
	./$(Q3_BIN)

run4: clean $(Q4_BIN)
	./$(Q4_BIN)

$(Q1_BIN): Question1/runner.c Question1/tests.c Question1/student.c Question1/student.h
	$(CC) $(CFLAGS) Question1/runner.c Question1/tests.c Question1/student.c -o $(Q1_BIN)

$(Q2_BIN): Question2/runner.c Question2/tests.c Question2/student.c Question2/student.h
	$(CC) $(CFLAGS) Question2/runner.c Question2/tests.c Question2/student.c -o $(Q2_BIN)

$(Q3_BIN): Question3/runner.c Question3/tests.c Question3/student.c Question3/student.h
	$(CC) $(CFLAGS) Question3/runner.c Question3/tests.c Question3/student.c -o $(Q3_BIN)

$(Q4_BIN): Question4/runner.c Question4/tests.c Question4/student.c Question4/student.h
	$(CC) $(CFLAGS) Question4/runner.c Question4/tests.c Question4/student.c -o $(Q4_BIN)

clean:
	rm -f $(Q1_BIN) $(Q2_BIN) $(Q3_BIN) $(Q4_BIN)