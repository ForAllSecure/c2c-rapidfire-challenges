/* Copyright 2016 ForAllSecure */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void execute_me() {
  printf("Awesome!\n");
}

void usage(char **argv) {
  printf("Usage: %s magic_bytes\n", argv[0]);
  exit(1);
}


int main(int argc, char *argv[]) {
  if(argc != 2) {
    usage(argv);
  }

  int user_input = *((int *)(argv[1]));
  if(user_input == 0xf24ab039) {
    execute_me();
  } else {
    printf("I got 0x%08x. That's not the bytes I was thinking of\n", user_input); 
  }
  return 0;
}
