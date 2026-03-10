#include <stdio.h>

int main() {

  int myNumbers[4] = {25, 50, 75, 100};
  int *p = myNumbers; // start of array

  for (int i = 0; i < 4; i++) {
    printf("%d\n", *p);
    p++; // move to next element in array
  }

  return 0;
}
