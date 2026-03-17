/*
* Author: Philip Y.
*/

#include <stdio.h>

int main() {

  int input;
  const int MINUTES_IN_HOUR = 60;

  printf("How many minutes in whole numbers: ");
  scanf("%d", &input);
  int hours = input / MINUTES_IN_HOUR;
  int minutes = input % MINUTES_IN_HOUR;
  printf("%d minutes is: %d hour(s) and %d minutes\n", input, hours, minutes);

  return 0;
}
