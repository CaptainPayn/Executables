/*
* Author: Philip Y.
*/
#include <stdio.h>

int main() {

  const float MERCURY_FACTOR = 0.38;
  const float VENUS_FACTOR = 0.91;
  const float MOON_FACTOR = 0.165;
  const float MARS_FACTOR = 0.38;
  const float JUPITER_FACTOR = 2.34;
  const float SATURN_FACTOR = 0.93;
  const float URANUS_FACTOR = 0.92;
  const float NEPTUNE_FACTOR = 1.12;
  const float PLUTO_FACTOR = 0.066;

  char name[30]; // declaring array to store name
  float weight;
  printf("What is your name: ");
  scanf("%s", name);
  printf("What is your earth weight: ");
  scanf("%f", &weight);
  if (!(weight > 0.00)){
    printf("Invalid input\n");
  } else {
    float weightOnMercury = weight * MERCURY_FACTOR;
    float weightOnVenus = weight * VENUS_FACTOR;
    float weightOnMoon = weight * MOON_FACTOR;
    float weightOnMars = weight * MARS_FACTOR;
    float weightOnJupiter = weight * JUPITER_FACTOR;
    float weightOnSaturn = weight * SATURN_FACTOR;
    float weightOnUranus = weight * URANUS_FACTOR;
    float weightOnNeptune = weight * NEPTUNE_FACTOR;
    float weightOnPluto = weight * PLUTO_FACTOR;

    printf("%s here are your weights on the solar system's planets:\n", name);
    printf("Weight on Mercury: %.2f\n", weightOnMercury);
    printf("Weight on Venus: %.2f\n", weightOnVenus);
    printf("Weight on Moon: %.2f\n", weightOnMoon);
    printf("Weight on Mars: %.2f\n", weightOnMars);
    printf("Weight on Jupiter: %.2f\n", weightOnJupiter);
    printf("Weight on Saturn: %.2f\n", weightOnSaturn);
    printf("Weight on Uranus: %.2f\n",  weightOnUranus);
    printf("Weight on Neptune: %.2f\n", weightOnNeptune);
    printf("Weight on Pluto: %.2f\n", weightOnPluto);
      }
  return 0;
}
