#include <stdio.h>

int main() {

  int myNumbers[4] = {25, 50, 75, 100};

  // printing 1st and 2nd element before the change
  printf("%d %d \n", *myNumbers, *(myNumbers + 1));

  // change the value of the 1st element to 13
  *myNumbers = 13;
  
  // change the value of the 2nd element to 17
  *(myNumbers + 1) = 17;

  // get the value of the 1st element
  printf("%d\n", *myNumbers);

  // get the value of the 2nd element
  printf("%d\n", *(myNumbers + 1));

  return 0;
}
