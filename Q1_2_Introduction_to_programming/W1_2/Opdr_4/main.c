#include <stdio.h>
#include "functions.h"

int main() {

    int input;

    input = read_int("Please enter a 3-digit number:");

    if (input > 999  || input < 100) {
        printf("Invalid input");
        return 1;
    }

    printf("The reversed of %d is: %1d%1d%-3d", input, input % 10, (input % 100) / 10, input / 100);

    return 0;
}


