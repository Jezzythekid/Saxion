//
// Created by Eigenaar on 18-10-2023.
//

#ifndef OPDR_3_DATEFUNCTIONS_H
#define OPDR_3_DATEFUNCTIONS_H

/// A function that checks if a year is a leapyear
/// @param year Year to check
/// @return bool: true = leapyear, false = regular.
bool CheckLeapyear(int year);

/// A funciton that checks how many days are in a specified month
/// @param monthNo Month to check. january = 1, february = 2, etc.
/// @param LeapYear set true if leap year.
int DaysInMonth(int monthNo, bool leapYear);

/// A function that asks the user to enter a valid date in the past.
/// @param date int array[3]
/// @return bool: true = valid, false = invalid.
bool AskDate(int date[3]);



#endif //OPDR_3_DATEFUNCTIONS_H
