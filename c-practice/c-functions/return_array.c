#include <stdio.h>

int calculateSum(int x, int y) {
  return x + y; // returning the sum of the two variables
}

int main() {

  // create array to store results
  int resultArr[6];

  // call function with diff args and store in array at diff indexes
  resultArr[0] = calculateSum(5, 0);
  resultArr[1] = calculateSum(4, 3);
  resultArr[2] = calculateSum(6, 9);
  resultArr[3] = calculateSum(8, 7);
  resultArr[4] = calculateSum(2, 2);
  resultArr[5] = calculateSum(0, 3);

  for (int i = 0; i < 6; i++) {
    printf("Result%d equals %d\n", i + 1, resultArr[i]); // notice the i + 1 is to start the output count from 1 instead of 0
  }

  return 0;
}
