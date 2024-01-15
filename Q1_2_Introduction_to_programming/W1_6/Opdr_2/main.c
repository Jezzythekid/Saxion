#include <stdio.h>
#include "math.h"
#include "functions.h"

// week 6 opdracht 2: Write a program that asks the user to enter two numbers,
// and then asks the user to enter an operator. The program should then print the result
// of applying the operator to the two numbers. All floating point numbers must be
// printed with 4 digits after the decimal point.

/// Asks the user to enter a valid operator, and returns the operator.
/// Valid operators are: +, -, *, /, ^ (exponentiation)
/// If the user enters an invalid operator, the user is asked again until a valid operator is entered.
/// @return The operator entered by the user.
char read_operator(void);

/// Returns the result of applying the given operator to the given numbers.
/// @param number1 The first number.
/// @param number2 The second number.
/// @param operator The operator.
/// @return The result of applying the operator to the two numbers.
float apply_operator(float number1, float number2, char operator);

/// Asks the user whether they want to perform another calculation, and returns true if the user wants to perform another calculation, and false otherwise.
/// @return true if the user wants to perform another calculation, and false otherwise.
bool perform_another_calculation(void);

int main(void) {

    // declare variables

    char operator;
    float first_number;
    float second_number;
    bool stopCalculator = false;

    // loop
    // ask user for an integer, call function read_operator, and ask for another integer
    // call function apply_operator om het resultaat te berekenen
    // druk resultaat af
    // vraag of gebruiker verder wil (call function perform_another_calcualtion)
    while (stopCalculator == false) {
        float answer;

        first_number = read_float("\n Please enter a number:");
        operator = read_operator();
        second_number = read_float("\nPlease enter a number:");

        answer = apply_operator(first_number, second_number, operator);

        printf("%.2f %c %.2f = %.2f", first_number, operator, second_number, answer);

        stopCalculator = !perform_another_calculation();
    }

    return 0;
}

char read_operator(void) {
    char operator;
    operator = read_char("\nplease enter an operator:");

    while (operator != '+' && operator != '-' && operator != '*' && operator != '/' && operator != '^') {
        operator = read_char("\nplease enter an VALID operator:");
    }

    return operator;
}

float apply_operator(float number1, float number2, char operator) {

    switch (operator) {
        case '+':
            return number1 + number2;
        case '-':
            return number1 - number2;
        case '*':
            return number1 * number2;
        case '/':
            return number1 / number2;
        case '^':
            return powf(number1, number2);
        default:
            return 0.0f;
    }

}

bool perform_another_calculation(void) {
    char input = read_char("\nDo you want to calculate another promt?");

    if (input == 'y') return true;
    else return false;

}
