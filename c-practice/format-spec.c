#include <stdio.h>

int main() {
  int myNumber = 15;
  // printf(myNumber) --> this will error out
  // You must specify format specifier or "placeholder"
  float myFloat = 1.3;
  char myLetter = 'P';

  printf("Notice the difference in output in the \"%%f\" vs the \"%%.2f\" similar to python f strings\n");
  printf("My number is %d, my float is %f and my letter is %c\n", myNumber, myFloat, myLetter);
  printf("My number is %d, my float is %.2f and my letter is %c\n", myNumber, myFloat, myLetter);
  return 0;
}
