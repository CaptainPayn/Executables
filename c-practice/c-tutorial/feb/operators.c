#include <stdio.h>

int main() {
  int itemPrice = 20;
  int shippingCost = 5;
  char currency = '$';

  int sum = itemPrice + shippingCost;
  printf("Sum of shipping and price is: %c%d\n", currency, sum);

  return 0;
}
