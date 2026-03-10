#include <stdio.h>

int main() {
  float myFloat = 12.99;
  double myDouble = 12.99;
  printf("My float %f\n", myFloat);
  printf("My double %lf\n", myDouble);

  // Utilizing sizeof and %zu format specifier will show you the size the each data type takes up in memory
  // Using the right data type will save memory and improve performance of you program
  printf("Size of myFloat variable in bytes is %zu\n", sizeof(myFloat));
  printf("Size of myDouble variable in bytes is %zu\n", sizeof(myDouble));
  return 0;
}

