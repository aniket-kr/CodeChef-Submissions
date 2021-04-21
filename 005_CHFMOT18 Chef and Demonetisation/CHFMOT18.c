#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void coin_count(unsigned amount, unsigned coins);

int main(void) {
  // first line contains number of test cases
  unsigned short cases;
  fscanf(stdin, "%hu", &cases);

  // next two lines contain 'S' and 'N', N is even
  unsigned amount = 0;
  unsigned coins = 0;
  for (unsigned short i = 0; i < cases; i++) {
    fscanf(stdin, "%u %u", &amount, &coins);
    coin_count(amount, coins);
  }

  return EXIT_SUCCESS;
}

inline void coin_count(unsigned amount, unsigned coins) {
  if (amount < coins) {
    if (amount == 1) {
      coins = amount;
    } else {
      coins = (amount % 2) ? amount - 1 : amount;
    }
  }

  unsigned count = 0;
  while (amount > 1) {
    count += amount / coins;
    amount = amount % coins;
    coins = (amount % 2) ? amount - 1 : amount;
  }

  if (amount) {
    count++;
  }

  fprintf(stdout, "%u\n", count);
}
