/* Copyright 2016 ForAllSecure */
#include <stdlib.h>
#include <stdio.h>

void execute_me() {
	printf("Awesome!\n");
}

int main(int argc, char *argv[]) {
	if(argc != 2) {
		puts("Give me one arg!");
		return 1;
	}
	unsigned x = atoi(argv[1]);
	volatile unsigned y = (x << 11) | (x >> 21);
	if(y == 0xFEEDFACE)
		execute_me();
	else
		puts("Nope.");
	return 0;
}
