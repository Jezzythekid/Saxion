#include <stdio.h>
#include "functions.h"

// Week 12, opdracht 2;
// Write a program that generates an array of 10 random integers between 0 and 100,
// and prints the array. The program should then print the smallest and largest number in the array.
// Next, the program should swap the smallest and largest number in the array, and print the array again.

/// Prints the array to the console, values comma-separated and on a single line
/// @param array The array to print.
/// @param length The length of the array.
void print_array(int array[], int length);

/// Fills an array with random numbers
/// @param array The array to fill.
/// @param length the length of the array
/// @param amount The amount of numbers to fill the array with
/// @param min the minimum value of the random int
/// @param max the maximum value of the random int
void random_fill_array(int array[], int amount, int min, int max);

/// Swaps the values of the two integers pointed to by `a` and `b`.
/// @param a The memory address of the first integer.
/// @param b The memory address of the second integer.
void swap(int * a, int * b);

/// Returns the address of the smallest number in the array.
/// @param array The array to search.
/// @param length The length of the array.
/// @return The address of the smallest number in the array, or NULL if the array is empty.
int* min_ptr(int array[], int length);

/// Returns the address of the largest number in the array.
/// @param array The array to search.
/// @param length The length of the array.
/// @return The address of the largest number in the array, or NULL if the array is empty.
int* max_ptr(int array[], int length);


// -------------------------------main------------------------------------


int main(void) {

    int numbers[100] = {};
    int* adrMax;
    int* adrMin;

    random_fill_array(numbers, 10, 0, 99);

    print_array(numbers, 10);

    adrMax = max_ptr(numbers, 10);
    adrMin = min_ptr(numbers, 10);

    printf("\nMax number = %d\nMin number = %d\n", *adrMax, *adrMin);

    swap(adrMax, adrMin);

    printf("\n");

    print_array(numbers, 10);

    read_string("\n\npress enter to continue...");

    return 0;
}


// ------------------------------functions----------------------------------


void random_fill_array(int array[], int amount, int min, int max) {

    for (int i = 0; i < amount; i++) {

        array[i] = random_int(min, max);

    }

}

void print_array(int array[], int length) {



    for (int i = 0; i < length - 1; i++) {

        printf("%d, ", array[i]);

    }

    printf("%d\n", array[length - 1]);

}
int* max_ptr(int array[], int length) {

    int max = array[0];
    int * ptr = array;

    for (int i = 1; i < length; i++) {

        if (array[i] > max) {
            max = array[i];
            ptr = &array[i];
        }

    }

    return ptr;

}


int* min_ptr(int array[], int length){

    int min = array[0];
    int* ptr = array;

    for (int i = 1; i < length; i++) {

        if (array[i] < min) {

            min = array[i];
            ptr = &array[i];
        }

    }

    return ptr;

}

// works & tested
void swap(int * a, int * b) {

    int temp;

    temp = *b;
    *b = *a;
    *a = temp;

}
