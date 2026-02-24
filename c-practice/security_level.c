#include <stdio.h>
#include <stdbool.h>


int main() {

  // set variables
  bool isLoggedIn = true;
  bool isAdmin = false;
  int securityLevel = 1;

  // if user is logged in and is either admin or has security level 2 or higher (1 being highest level)
   if (isLoggedIn && (isAdmin || securityLevel <= 2)) {
    printf("Access granted\n");
  } else {
    printf("Access denied\n");
  }
  return 0;
}
