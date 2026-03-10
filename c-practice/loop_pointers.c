#include <stdio.h>

int main() {

  // set up variable and array
  int myNumbers[4] = {25, 50, 75, 100};
  
  // set up pointer to array
  int *ptr = myNumbers;
  
  // set up index variable
  int i;

  // loop through array using for loop
  for (i = 0; i < 4; i++) {
    printf("%d\n", *(ptr + i));
  }

  return 0;
}
