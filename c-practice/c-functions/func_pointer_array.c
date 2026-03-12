#include <stdio.h>

void add() { printf("Add\n"); }
void subtract() { printf("Subtract\n"); }
void multiply() { printf("Multiply\n"); }

int main() {

  void (*operations[3])() = { add, subtract, multiply };
  for (int i = 0; i < 3; i++) {
    operations[i]();
  }
  return 0;
}
