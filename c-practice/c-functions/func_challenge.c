#include <stdio.h>

// declaring add function
int add(int x, int y);

int main() {

  int result = add(5, 3);
  printf("%d\n", result);
  return 0;
}

// defining add function
int add(int x, int y) {
  return x + y;
}
