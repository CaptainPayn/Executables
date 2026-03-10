#include <stdio.h>

int main() {

  int myNumbers[3] = {20, 30, 40};
  int *p = myNumbers; // myNumbers[0]

  printf("%d\n", *p); // 20
  p++;                // move to myNumbers[1]
  printf("%d\n", *p); // 30
  p--;                // move back to myNumbers[0]
  printf("%d\n", *p); // 20

  p += 2;             // jump to myNumbers[2]
  printf("%d\n", *p); // 40
  return 0;
}
