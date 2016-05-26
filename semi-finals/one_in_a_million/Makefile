.PHONY: all clean

all: one_in_a_million

clean:
	rm one_in_a_million

one_in_a_million: one_in_a_million.c
	$(CC) -std=gnu99 -Wall -m32 -Os -o $@ $<
