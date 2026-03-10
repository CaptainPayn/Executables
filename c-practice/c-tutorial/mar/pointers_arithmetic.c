#include <stdio.h>

int main() {
  int myNumbers[2] = {1, 2};
  char letters[] = "Hi"; // 'H', 'i', '\0'
  
  int *pi = myNumbers; // int pointer
  char *pc = letters; // char pointer
  
  printf("%p\n", (void*)pi);
  printf("%p\n", (void*)(pi + 1)); // moves by sizeof(int) (4 bytes)
  printf("%p\n", (void*)(pi + 2)); // moves by sizeof(int) (4 bytes)
  
  printf("%p\n", (void*)pc);
  printf("%p\n", (void*)(pc + 1)); // moves by 1 byte
  return 0;
}

