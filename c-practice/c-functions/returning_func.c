#include <stdio.h>

int calculateSum(int x, int y) {
  return x + y; // returning the sum of the two variables
}

int main() {

  // declare variables to store the return values of the function
  // passing in different variables
  int result1 = calculateSum(5, 2);
  int result2 = calculateSum(8, 9);
  int result3 = calculateSum(2, 12);

  printf("result1 is: %d\n", result1);
  printf("result2 is: %d\n", result2);
  printf("result3 is: %d\n", result3);

  return 0;
}
