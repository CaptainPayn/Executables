#include <stdio.h>

int main() {

  FILE *fptr;

  // create file
  fptr = fopen("newfile.txt", "a");
  fprintf(fptr, "Adding text\n");

  // close the file
  fclose(fptr);

  return 0;
}
