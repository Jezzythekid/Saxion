#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

// week 5 opdracht 4: fill and print (csv) an array[20], with random integers.
// Then print the same array with all the zero's to the end of the array

// example output:
//  >Contents (random):  1,  2,  3,  4,  5,  6,  7,  8,  9,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  0
//  >Contents (sorted):  1,  2,  3,  4,  5,  6,  7,  8,  9,  1,  2,  3,  4,  5,  6,  7,  8,  9,  0,  0

/// Fills the content af an array with random integers
/// @param array array to fill
/// @param size size of the array
void Fill_array_rng(int array[], int size);

/// prints the content of an array comma seperated
/// @param array array to print
/// @param size size of the array
void Print_csv(int array[], int size);

int main(void) {

    // declare variables
    const int SIZE = 10;

    int array[SIZE];
    int NoOfZeros = 0;

    // fill the array with random integers and print it comma seperated
    Fill_array_rng(array, SIZE);
    Print_csv(array, SIZE);
    printf("\n");

    // for loop though the array
    //  if index is zero NoOfZeros++
    //  else index = index[i - 1]

    for (int i = 0; i < SIZE; i++) {
        if (array[i] == 0) ++NoOfZeros;
        else array[i - NoOfZeros] = array[i];
    }

    // add the zeros

    for (int i = SIZE - NoOfZeros; i < SIZE; i++) {
        array[i] = 0;
    }

// print the array again
    Print_csv(array, SIZE);

    return 0;
}

void Fill_array_rng(int array[], int size) {
    for (int i = 0; i < size; i++) {
        array[i] = random_int(0,9);
    }
}

void Print_csv(int array[], int size) {
    printf("%d", array[0]);
    for (int i = 1; i < size; i++) {
        printf(", %d", array[i]);
    }
    printf("\n");
}


