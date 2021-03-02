/**
 * AUTHOR: Aniket Kumar
 * DATE: 2 March 2021
 */

#include <stdio.h>
#include <stdlib.h>


int main(void)
{
  float balance = 0;
  short request = 0;

  fscanf(stdin, "%hd %f", &request, &balance);

  if (request % 5 != 0) {
    fprintf(stdout, "%.2f", balance);
  } else if ((request + 0.5) > balance) {
    fprintf(stdout, "%.2f", balance);
  } else {
    fprintf(stdout, "%.2f", (balance - request - 0.5));
  }

  return EXIT_SUCCESS;
}
