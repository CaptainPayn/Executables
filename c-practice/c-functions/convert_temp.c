#include <stdio.h>

// function to convert fahrenheit to celsius
float toCelsius(float fahrenheit) {
  return (5.0 / 9.0) * (fahrenheit - 32.0);
}

int main() {

  // set a fahrenheit value
  float f_value = 98.8;

  // call the function with the fahrenheit value
  float result = toCelsius(f_value);

  // print the fahrenheit value
  printf("Fahrenheit: %.2f\n", f_value);

  // print the converted value
  printf("Convert fahrenheit to celsius: %.2f\n", result);

  return 0;
}
