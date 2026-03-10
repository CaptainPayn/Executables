#include <stdio.h>

int main() {
  // create string
  char firstName[30];

  // ask user for text
  printf("Enter your first name: ");

  // put text to variable
  scanf("%s", firstName);

  printf("Hello %s\n", firstName);

  return 0;
}
