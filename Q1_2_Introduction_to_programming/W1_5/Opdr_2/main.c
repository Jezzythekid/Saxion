#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

// week 5 opdracht 2: print an array and let the user enter 3 integers to find it in the
// main array



int main(void) {

    //declare variables
    const short int SIZE_ARRAY = 10;
    const short int SIZE_USR_ARRAY = 3;

    int array[SIZE_ARRAY];
    int user_array[SIZE_USR_ARRAY];
    int index = -1;

    //fill array[10] with random integers
    for (int i = 0; i < SIZE_ARRAY; i++) {
        array[i] = random_int(1, 10);
    }

    //print array csv
    printf("\n%d", array[0]);
    for (int i = 1; i < SIZE_ARRAY; i++) {
        printf(", %d", array[i]);
    }

    //fill user_array[3] by asking user
    printf("\n");
    for (int i = 0; i < SIZE_USR_ARRAY; i++) {
        user_array[i] = read_int("Enter a number");
    }

    //find the user_array[3] in the array[10]
    //  find first number of user_array[3] in array[10] and store its index
    //  check if the 2nd number in user_array[3] also occurs in array[10] after the index of the 1st
    //  check if the 3rd number in user_array[] also occurs in array[10] after the index of the 2nd
    for (int i = 0; i < SIZE_ARRAY - 2; i++) {
        if (array[i] == user_array[0] &&
            array[i+1] == user_array[1] &&
            array[i+2] == user_array[2]) {

            index = i;
        }
    }

    //print if user_array[3] is contained in array[10] and its index
    printf("\nThe Array {");
    printf("%d", user_array[0]);
    for (int i = 1; i < SIZE_USR_ARRAY; i++) {
        printf(", %d", user_array[i]);
    }
    if (index != -1) {
        printf("} is contained in the larger array, starting at index %d", index);
    }
    else printf("} is not contained in the larger array;");


    return 0;
}


