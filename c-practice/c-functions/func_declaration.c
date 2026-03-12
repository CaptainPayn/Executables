#include <stdio.h>

// function declaration
int myFunction(int x, int y);

// main method
int main() {

  int result = myFunction(5, 3); // call the function
  printf("%d\n", result);
  return 0;
}

// function definition
int myFunction(int x, int y) {
  return x + y;
}
