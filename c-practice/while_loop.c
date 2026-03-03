#include <stdio.h>

int main() {

  int i = 0;

  while (i < 5) {
    printf("%d\n", i);
    i++;
  }

  printf("Now counting down from 3!\n");

  int countdown = 3;

  while (countdown > 0) {
    printf("%d\n", countdown);
    countdown--;
  }
  return 0;
}
