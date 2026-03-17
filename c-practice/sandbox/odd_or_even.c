/*
* Author: Philip Y.
*/
#include <stdio.h>

int main() {

  int num;
  printf("Enter an integer: ");
  scanf("%d", &num);
  if (num % 2 == 0) {
    printf("Your number is even!\n");
  } else {
    printf("Your number is odd!\n");
  }

  return 0;
}
