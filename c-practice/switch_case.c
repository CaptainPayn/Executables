#include <stdio.h>

int main() {
  int day = 6;
  switch (day) {
    case 6:
      printf("Today is Saturday\n");
      break;
    case 7:
      printf("Today is Sunday\n");
      break;
    default: // akin to "*)" in a bash case statement
      printf("Looking forward to the weekend\n");
  }
  return 0;
}
