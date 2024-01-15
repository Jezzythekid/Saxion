#include "functions.h"

bool AskDate(int date[3]) {
    int curDate[3] = {0};

    date[0] = read_int("Please enter a year:");
    date[1] = read_int("Please enter a month:");
    date[2] = read_int("Please enter a day:");

    get_current_date(curDate);

    // check if years are in bounds
    if (curDate[0] > date[0]) return true;
    if (curDate[0] < date[0]) return false;

    if (curDate[1] > date[1]) return true;
    if (curDate[1] < date[1]) return false;

    if (curDate[2] > date[2]) return true;
    if (curDate[2] < date[2]) return false;

        return false;
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
