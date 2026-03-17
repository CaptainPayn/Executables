#include <stdio.h>

void calculateDistance() {

  int time; // declare var
  printf("Enter time in seconds between sound of thunder and flash of lightning: ");
  scanf("%d", &time); // getting input from STDIN

  // error handling
  if (!(time > 0)) {
    printf("Invalid input\n");
  } else {
    int distance = time / 5; // simple arithmetic to get storm distance
    printf("You are %d miles away from the storm\n", distance);
  }
}

int main() {
  calculateDistance(); // call the function
  return 0;
}
