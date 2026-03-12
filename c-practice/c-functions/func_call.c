#include <stdio.h>

// declare two functions
void myFunction();
void myOtherFunction();

int main() {

  myFunction(); // call myFunction from main
  return 0;
}

// define myFunction
void myFunction() {
  printf("Some text in myFunction\n");
  myOtherFunction(); // call myOtherFunction from myFunction
}

// define myOtherFunction
void myOtherFunction() {
  printf("Some more text but from myOtherFunction\n");
}
