/* Copyright 2016 ForAllSecure */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void execute_me() {
  printf("Awesome!\n");
}

void usage() {
  fprintf(stderr, "./firetruck string\n");
  exit(1);
}

int main(int argc, char** argv) {
  if(argc != 2) {
    usage();
  }

  if ( *(int*)(&argv[1][0]) != 1667588969 ) {
    puts("That's not the best truck");
    exit(1);
  }

  if ( *(int*)(&argv[1][4]) != 1835099506) {
    puts("That's not the best truck");
    exit(1);
  }

  execute_me();

  return 0;
}
