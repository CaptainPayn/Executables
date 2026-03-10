#include <stdio.h>

int main() {

  int myNum = 5; //normal var
  int *ptr = &myNum; // pointer to int
  int **pptr = &ptr; // pointer to pointer

  printf("myNum = %d before the change\n", myNum); // prints 5
  
  **pptr = 20; // changes myNum

  printf("myNum = %d after the change\n", myNum); // prints 20

  return 0;
}
