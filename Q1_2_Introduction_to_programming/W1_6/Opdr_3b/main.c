#include <stdio.h>
#include "functions.h"
#include "DateFunctions.h"

// week 6 opdracht 3: Write a program that asks the user to enter a day, month, and year,
// and then prints the day of the year, i.e. a number between 1 and 366.

int main(void) {

    // Declare variables
    int date[3] = {}; // 0 = years, 1 = months, 2 = days
    int days = 0;
    bool leapyear;

    // Check if date is valid
    //  simple if statement with the current date
    AskDate(date);

    leapyear = CheckLeapyear(date[0]);

    // add all days of the months in date[1] together
    for (int i = 1; i < date[1]; i++) {
        days += DaysInMonth(i, leapyear);
    }

    // add the remaining days in date[2] to the count
    days += date[2];

    // print the total days
    printf("%d-%d-%d is day %d of the year %d", date[2], date[1], date[0], days, date[0]);

    return 0;
}


