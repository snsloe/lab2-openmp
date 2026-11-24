CC      := gcc
CFLAGS  := -O2 -Wall -Wextra -std=c11 -D_POSIX_C_SOURCE=200809L -fopenmp
LDFLAGS := -lm

.PHONY: all task1 clean

all: task1

task1: task1/calculate_pi.c
	$(CC) $(CFLAGS) $^ -o task1/calculate_pi $(LDFLAGS)
