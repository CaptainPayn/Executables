#include <stdio.h>

int main() {

  int myNum = 10; //normal var
  int *ptr = &myNum; // pointer to int
  int **pptr = &ptr; // pointer to pointer

  printf("myNum = %d\n", myNum);
  printf("*ptr = %d\n", *ptr);
  printf("**pptr = %d\n", **pptr);

  return 0;
}
