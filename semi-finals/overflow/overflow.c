/* Copyright 2016 ForAllSecure */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void execute_me() {
  printf("Awesome!\n");
}

void usage(char ** argv) {
  printf("Usage: %s your_name\n", argv[0]);
  exit(1);
}

int main(int argc, char *argv[]) {
  if(argc != 2) {
    usage(argv);
  }

  char hello_string[20];
  strcpy(hello_string, "Hello ");
  strcpy(hello_string + 6, argv[1]);
  printf("%s!\n", hello_string);
  return 0;
}
