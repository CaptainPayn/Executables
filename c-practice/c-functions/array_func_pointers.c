#include <stdio.h>

void add(int a, int b) { printf("Result: %d\n", a + b); }
void subtract(int a, int b) { printf("Result: %d\n", a + b);
void multiply(int a, int b) { printf("Multiply\n", a * b); }

int main() {

  void (*operations[3])() = { add, subtract, multiply };
  for (int i = 0; i < 3; i++) {
    operations[i]();
  }
  return 0;
}

int main() {



  return 0;
}
