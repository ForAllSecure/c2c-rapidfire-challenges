/* Copyright 2016 ForAllSecure */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 4

void execute_me() {
  printf("Awesome!\n");
}

void nope() {
  puts("You have failed.");
}

void usage() {
  puts("Usage: ./firebird <address to write to> <value to write there>");
}

void (*printer) (void) = nope;

int main(int argc, char *argv[]) {
  if (argc < 3) {
    usage();
    return 1;
  }
  printf("Value being written: %x\n", *(unsigned int *)(argv[2]));
  printf("Address being written to: %x\n", *(unsigned int*)argv[1]);
  **(unsigned int **)(argv[1]) = *(unsigned int *)(argv[2]);
  printer();
  return 0;
}
