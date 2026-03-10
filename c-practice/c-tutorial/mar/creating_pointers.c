#include <stdio.h>

int main() {

  int myAge = 43;
  int* ptr = &myAge;

  // print value of myAge (43)
  printf("%d\n", myAge);

  // output the memory address of myAge
  printf("%p\n", &myAge);

  // ouput the memory address of myAge referencing the pointer
  printf("%p\n", ptr);

  // output the value of myAge dereferencing with the pointer (note the %d and the *ptr)
  printf("%d\n", *ptr);

  return 0;
}
