#include <stdio.h>
#include "functions.h"

//Opdacht 1, berekenen van de oppervlakte:

int main() {

    float radius;
    float pi = 3.14159265358979323846f;
    float area;

    radius = read_float("Please enter the radius of the circle:");

    area = pi * radius * radius;

    printf("The surface area of a circle with radius %.2f is %.2f", radius, area);

    return 0;
}
