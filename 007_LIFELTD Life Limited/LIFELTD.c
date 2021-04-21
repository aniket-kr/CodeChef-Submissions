#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void read_logo(char logo[3][3]);
bool has_L(char logo[3][3], unsigned short row, unsigned short col);


int main(void) {
  unsigned short cases = 0;
  fscanf(stdin, "%hu", &cases);

  char logo[3][3] = { 0 };
  for (unsigned short i = 0; i < cases; i++) {
    read_logo(logo);

    if (has_L(logo, 0, 0) ||
        has_L(logo, 0, 1) ||
        has_L(logo, 1, 0) ||
        has_L(logo, 1, 1)) {
      fprintf(stdout, "yes\n");
    } else {
      fprintf(stdout, "no\n");
    }
  }

  return EXIT_SUCCESS;
}


inline void read_logo(char logo[3][3]) {
  char tmp_str[4] = "";
  for (int j = 0; j < 3; j++) {
    fscanf(stdin, "%s", tmp_str);
    logo[j][0] = tmp_str[0];
    logo[j][1] = tmp_str[1];
    logo[j][2] = tmp_str[2];
  }
}


inline bool has_L(char logo[3][3], unsigned short row, unsigned short col) {
  // it is garuanteed by caller that indices won't go out of bounds
  return logo[row][col] == 'l' &&
    logo[row + 1][col] == 'l' &&
    logo[row + 1][col + 1] == 'l';
}
