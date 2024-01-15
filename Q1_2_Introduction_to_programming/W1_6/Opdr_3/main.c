#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "DateFunctions.h"

// week 6 opdracht 3: Write a program that asks the user to enter a day, month, and year,
// and then prints the day of the year, i.e. a number between 1 and 366.

int main(void) {

    // Declare variables
    int date[3] = {}; // 0 = years, 1 = months, 2 = days
    int curDate[3]= {};
    bool dateValid;
    int days = 0;

    get_current_date(curDate);

    // Check if date is valid
    //  simple if statement with the current date
    dateValid = AskDate(date);
    while (dateValid == false) {
        printf("Invalid date, please try again\n\n");
        dateValid = AskDate(date);
    }

    // todo check if year is leap year



    // add the days of all months + the current day in the month
    for (int i = date[1]; i <= curDate[1]; i++) {
        days += DaysInMonth(i, false);
        i++;
    }


    printf("%d %d %d is %d ago", date[2], date[1], date[0], days);

    return 0;
}


