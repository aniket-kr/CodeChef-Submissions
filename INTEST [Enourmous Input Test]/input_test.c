#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  unsigned lines, divisor;
  fscanf(stdin, "%u %u", &lines, &divisor);

  unsigned counter = 0;
  unsigned num;
  for (unsigned i = 0; i < lines; i++)
  {
    fscanf(stdin, "%u", &num);
    counter += (num % divisor) ? 0 : 1;
  }

  fprintf(stdout, "%u", counter);

  return EXIT_SUCCESS;
}