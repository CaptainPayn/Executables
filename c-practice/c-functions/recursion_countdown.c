#include <stdio.h>

// declare countdown func
void countdown(int n);

int main() {
  // call countdown passing in var
  countdown(15);
  return 0;
}

// define countdown func and calling itself
void countdown(int n) {
  if (n > 0) {
    printf("%d\n", n);
    countdown(n - 1);
  }
}
