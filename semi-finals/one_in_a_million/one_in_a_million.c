/* Copyright 2016 ForAllSecure */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void execute_me() {
	printf("Awesome!\n");
}

int main(int argc, char *argv[]) {
	srand(time(NULL));
	printf("Guess the number.\n");
	int guess;
	scanf("%d", &guess);
	volatile int x = rand();
	volatile int y = 1000000;
	volatile int z = x % y;
	if(guess == z)
		execute_me();
	else
		printf("Nope, the answer was %d\n", z);
	return 0;
}
