#include <stdio.h>

// global variable x
int x = 5;

void myFunction() {
  // we can use x here
  printf("Accessing variable x in myFunction\n");
  printf("%d\n", x);
}

int main() {

  myFunction();

  // we can also use x here
  printf("Accessing variable x inside the main()\n");
  printf("%d\n", x);

  return 0;
}
