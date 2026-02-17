#include <stdio.h>

int main() {
  float myFloat = 12.34;
  double myDouble = 19.99;
  printf("My float is %f\n", myFloat);

  // Safer to use double for calculations but it takes up double the memory
  printf("And my double is %lf\n", myDouble);   return 0;
}
