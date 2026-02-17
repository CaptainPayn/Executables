#include <stdio.h>
#include <stdbool.h>

int main() {
  int myAge = 27;
  int voteAge = 18;

  if (myAge >= voteAge) {
    printf("Old enough to vote\n");
  } else {
    printf("Not old enough to vote\n");
  }
  return 0;
}
