#include <stdio.h>
#include "functions.h"
#include "stdbool.h"

// Week 3 Opdracht 2: Write a program that asks the user to enter numbers, one after another,
// until the user enters the number 0, in which case the program quits.

int main() {

    int currentNumber = -1;
    signed int highestNumber = -32767;          //minimal value of an signed int
    signed int secondHighestNumber = -32767;    //minimal value of an signed int
    int noOfNumbers = 1;


    currentNumber = read_int("Please enter a number:\n"); //13
    while (currentNumber != 0) {
        if (currentNumber > highestNumber) { //13
            secondHighestNumber = highestNumber; //2nd = 12
            highestNumber = currentNumber; //hi = 15
        }
        else if (currentNumber > secondHighestNumber) secondHighestNumber = currentNumber;  //13

        noOfNumbers++;
        currentNumber = read_int("Please enter a number:\n"); //13
    }

    if (noOfNumbers <= 2) printf("Not enough numbers entered.");
    else printf("Second highest number is %d", secondHighestNumber);

    return 0;
}
