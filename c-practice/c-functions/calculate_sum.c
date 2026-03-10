#include <stdio.h>

void calculateSum() {
  int x = 5;
  printf("Value of x: %d\n", x);
  int y = 10;
  printf("Value of y: %d\n", y);
  int sum = x + y;
  printf("The sum of x + y is: %d\n", sum);
}

int main() {
  calculateSum(); // call the function
  return 0;
}
