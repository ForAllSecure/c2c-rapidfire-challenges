.PHONY: all clean

all: rapidreversing

clean:
	rm rapidreversing

rapidreversing: rapidreversing.c
	$(CC) -std=gnu99 -Wall -m32 -O2 -o $@ $<
