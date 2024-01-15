#include <stdio.h>
#include "stdlib.h"
#include "functions.h"
#include "stdbool.h"

// Week 4 opdracht 2: Write a program that asks the user to enter a number of floating point numbers,
// one after another, until the user enters the number 0.
// The user must not be allowed to enter more than 10 numbers
// if the user has not entered a zero after 10 numbers, the program must stop asking for more input.
// After the user has entered the numbers,the program must print the numbers in reverse order.
// Also, the sign of each number must be flipped.

int main(void) {

    const int MAX_NUMBERS = 10;
    const float CMD_STOP = 0.0f;


    int startArray = MAX_NUMBERS;
    float userInput = -1.0f;
    float numbers[10] = {0};

    system("cls");

    //userInput = read_float("Enter a number (0 to stop):\n");

    // Entering userInput in an array
    // The for loop starts with "i" having maximum index that the array can hold (10 - 1 = 9),
    // as its starting value. at each iteration "i" is written to int "startArray", indicating
    // the starting point of the array to be printed, thus flipping the array.

    for (int i = MAX_NUMBERS - 1; i >= 0; i--) {

        //flipping the sign

        userInput = read_float("Enter a number (0 to stop):\n");

        if (userInput == 0.0f) {
//            printf("\nMaximum (%d) numbers entered, "
//                   "printing numbers reversed and flipped ...\n\n", MAX_NUMBERS);
            break;
        }

        userInput = 0 - userInput;

        numbers[i] = userInput;
        startArray = i;


    }

    if (userInput == CMD_STOP && startArray != MAX_NUMBERS) {

        printf("\nPrinting numbers reversed and flipped\n\n");
    }

    // Printing of the array stating with startArray

    while (startArray != MAX_NUMBERS) {

        if (startArray == MAX_NUMBERS - 1) printf("%.2f\n ", numbers[startArray]);
        else printf("%.2f, ", numbers[startArray]);

        startArray++;
    }


    return 0;
}


