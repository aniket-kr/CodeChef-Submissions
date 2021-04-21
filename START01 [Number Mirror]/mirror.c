#include <stdio.h>
#include <stdlib.h>

int main(void) {
  unsigned num;
  fscanf(stdin, "%u", &num);
  fprintf(stdout, "%u\n", num);

  return EXIT_SUCCESS; 
}