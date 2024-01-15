#include <stdio.h>
#include "functions.h"


bool CheckLeapyear(int year) {
    bool divisible_by_4 = year % 4 == 0;    // check if year is divisible by 4
    bool divisible_by_100 = year % 100 == 0;    // check if year is divisible by 100
    bool divisible_by_400 = year % 400 == 0;    // check if year is divisible by 400
    bool leap_year = divisible_by_4 && (!divisible_by_100 || divisible_by_400); // check if year is a leap year
    return leap_year;
}

int DaysInMonth(int monthNo, bool leapYear) {
    switch (monthNo) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            if (leapYear) return 29;
            else return 28;
        default:
            return 0;
    }
}

bool DateInBounds(int date[3]) {

    bool leapyear = CheckLeapyear(date[0]);

    if (date[0] < 0) return false;

    if (date[1] > 12) return false;
    if (date[1] < 0) return false;

    if (date[2] > DaysInMonth(date[1], leapyear)) return false;
    if (date[2] < 0) return false;

    return true;
}

bool AskDate(int date[3]) {

    bool dateValid = false;

    date[0] = read_int("Please enter a year:");
    date[1] = read_int("Please enter a month:");
    date[2] = read_int("Please enter a day:");

    dateValid = DateInBounds(date);

    while (dateValid == false) {
        printf("Invalid date please try again\n\n");

        date[0] = read_int("Please enter a year:");
        date[1] = read_int("Please enter a month:");
        date[2] = read_int("Please enter a day:");

        dateValid = DateInBounds(date);
    }


    return true;
}
