/*
* Author: Philip Y.
* When compiling you must specify -lm to prevent unreferenced errors
*/
#include <stdio.h>
#include <math.h>

int main() {

  float principalInvestment;
  float interestRate;
  float timesAYear;
  int years;
  float futureValue;

  printf("Enter starting principal: ");
  scanf("%f", &principalInvestment);
  printf("Enter annual interest rate: ");
  scanf("%f", &interestRate);
  interestRate = interestRate / 100;
  printf("How many times a year is the interest compounded: ");
  scanf("%f", &timesAYear);
  printf("How many years will the account earn interest: ");
  scanf("%d", &years);

  // formula FV=PV(1+r/m)**mt
  futureValue = principalInvestment * pow(1 + interestRate / timesAYear, timesAYear * years);
  printf("At the end of %d years you will have $%.2f\n", years, futureValue);

  return 0;
}
