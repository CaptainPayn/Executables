#include <stdio.h>

int main() {

  int myNumbers[4] = {25, 50, 75, 100};

  // get memory address of the myNumbers array
  printf("%p\n", myNumbers);

  // get memory address of the first array element
  printf("%p\n", &myNumbers[0]);

  // since myNumbers is a pointer to the first element
  // we can use the * operator to access
  printf("%d\n", *myNumbers);

  // accessing the rest of the elements just increment the pointer (+1, +2, etc.)
  printf("%d\n", *(myNumbers + 1)); // gets 2nd element in myNumbers
  printf("%d\n", *(myNumbers + 2)); // gets 3rd element in myNumbers

  return 0;
}
