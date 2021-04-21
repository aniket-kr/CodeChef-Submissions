#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  unsigned short cases;
  fscanf(stdin, "%hu", &cases);

  unsigned short a, b;
  for (unsigned short i = 0; i < cases; i++)
  {
    fscanf(stdin, "%hu %hu", &a, &b);
    fprintf(stdout, "%hu\n", a + b);
  }

  return EXIT_SUCCESS;
}