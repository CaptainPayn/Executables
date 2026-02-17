#include <stdio.h>

int main() {
  int items = 50;
  float cost_per_item = 9.99;
  float total_cost = items * cost_per_item;
  char currency = '$';

  printf("Number of items: %d\n", items);
  printf("Cost per item: %c %.2f\n", currency, cost_per_item);
  printf("Total Cost: %c %.2f\n", currency, total_cost);

  return 0;
}
