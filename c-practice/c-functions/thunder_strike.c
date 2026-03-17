/*
* Author: Philip Y
*/
#include <stdio.h>

void calculateDistance() {

  float time; // declare var
  printf("Enter time in seconds between sound of thunder and flash of lightning: ");
  scanf("%f", &time); // getting input from STDIN

  // error handling
  if (!(time > 0)) {
    printf("Invalid input\n");
  } else {
    float distance = time / 5; // simple arithmetic to get storm distance
    printf("You are %.2f miles away from the storm\n", distance);
  }
}

int main() {
  calculateDistance(); // call the function
  return 0;
}
