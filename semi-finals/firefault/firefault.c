/* Copyright 2016 ForAllSecure */
#include <string.h>
#include <stdio.h>

void execute_me() {
	printf("Awesome!\n");
}

int done = 0;

int main() {
        char buf[32];
        volatile int *done_ptr = &done;
	gets((void*)buf);
        *done_ptr = 1;
	printf("Hi %s!\n", buf);
	if(!done) puts("what?");
	return 0;
}
