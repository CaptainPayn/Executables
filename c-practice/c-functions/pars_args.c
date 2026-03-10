#include <stdio.h>

void myFunction(char name[], int age){
  printf("Hello %s. You are %d years old\n", name, age);
}

int main() {

  myFunction("Phil", 27);
  myFunction("Alex", 12);
  myFunction("Joe", 22);

  return 0;
}
