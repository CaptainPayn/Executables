#include <stdio.h>

int main() {
  // e or E stands for "times 10 to the power of..."
  // So in the below example it is 35 * 10 to the power of 3 (or 35 * 10^3)
  float myFloat = 35e3;
  double myDouble = 35e3;
  printf("My float %f\n", myFloat);
  printf("My double %lf\n", myDouble);
  return 0;
}

