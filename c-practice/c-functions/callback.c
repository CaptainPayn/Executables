#include <stdio.h>

// declaring and defining greetMorning & greetEvening
void greetMorning() { printf("Good morning!\n") ;}
void greetEvening() { printf("Good evening!\n") ;}

// declaring and defining greet function that takes in function pointer as argument
void greet(void (*func)()) {
  func();
}

int main() {
  // calling greet function and passing in other functions to it
  greet(greetMorning);
  greet(greetEvening);
  return 0;
}
