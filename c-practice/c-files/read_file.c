#include <stdio.h>

int main() {

  FILE *fptr;

  // open file in read mode
  fptr = fopen("newfile.txt", "r");

  // create array to store file strings
  char myString[100];

  // read content line by line
  while(fgets(myString, 100, fptr)) {
    printf("%s", myString);
  }
  
  // close the file
  fclose(fptr);

  return 0;
}
