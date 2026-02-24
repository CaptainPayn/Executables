#include <stdio.h>

int main() {
  int a = 200;
  int b = 33;
  int c = 500;
  if (a > b || c < a){
    printf("One of the conditions are true\n");
  }
  if (!(a > c)) {
    printf("a is not greater than c\n");
  }
  return 0;
}
