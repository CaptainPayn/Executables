#include <stdio.h>

void myFunction(int myNumbers[5]) {
  for (int i = 0; i < 5; i++) {
    printf("%d\n", myNumbers[i]);
  }
}

int main() {

  // create array
  int myNumbers[5] = {12, 13, 14, 15, 16};
  // pass in array to function
  myFunction(myNumbers);

  return 0;
}
