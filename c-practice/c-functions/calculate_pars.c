#include <stdio.h>

void calculateSum(int y, int x) {
  int sum = x + y;
  printf("The sum of %d + %d is: %d\n", x, y, sum);
}

int main() {
  // call the function with passing parameters
  calculateSum(5, 3);
  calculateSum(8, 2);
  calculateSum(10, 12);
  return 0;
}
