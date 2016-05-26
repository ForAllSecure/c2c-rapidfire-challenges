.PHONY: all
all: snaaaake

snaaaake: snaaaake.c
	gcc -O1  -o $@  $^ -fno-stack-protector -z execstack -U_FORTIFY_SOURCE -D_FORTIFY_SOURCE=0 -fno-PIE -lcurses -lncurses -m32
