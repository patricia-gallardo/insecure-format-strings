/*
 * Adapted from Hacking, the Art of Exploitation by Jon Erickson
 * Turn off ASLR for a specific run
 * setarch `uname -m` -R ./getenvaddr PATH
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

  if (argc < 3) {
    printf("Usage: %s <environment var> <binary> \n", argv[0]);
    exit(0);
  }

  char *pointer = getenv(argv[1]);

  int program_length_difference =  (strlen(argv[0]) - strlen(argv[2]))*2;
  pointer += program_length_difference;
  size_t variable_length = strlen(argv[1]);
  pointer -= variable_length;
  printf("%s will be at %p in %s\n", argv[1], pointer, argv[2]);
}
