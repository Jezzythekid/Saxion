#include <stdio.h>
#include <malloc.h>
#include "functions.h"
#include "string.h"

// Week 12, opdracht 3
// Write a program that asks the user to enter three strings, and then prints
// the strings in alphabetical order. To do this, the program needs to sort the three strings
// in lexicographical order

/// Swaps the two strings if the first string is alphabetically larger than the second string.
/// @param a The memory address of the first string.
/// @param b The memory address of the second string.
void sort_two_strings(const char ** a, const char ** b);

/// Swats two string
/// @param a The memory address of the first string.
/// @param b The memory address of the second string.
void swap_strings( const char **a, const char **b);

/// Function that lets the user enter multiple strings
/// @param prompt The prompt to print.
/// @param amount amount of strings to read.
/// @param ptr the pointer to the string array
void read_strings(const char * prompt, int amount, char *ptr[][100]);

int main(void) {

    char *ptr[3][100];

    // let the user enter 3 strings.
    read_strings("please enter a string ", 3, ptr);

    // compare the strings and swap if needed
    //  1. compare the first and second strings and swap if needed
    //  2. compare the second and third strings and swap if needed
    //  3. compare the first and third strings and swap if needed
    sort_two_strings((const char **) &ptr, (const char **) &ptr[1]);
    sort_two_strings((const char **) &ptr[1], (const char **) &ptr[2]);
    sort_two_strings((const char **) &ptr, (const char **) &ptr[1]);

    // print the sorted strings.

    printf("\n%s %s %s", *ptr[0], *ptr[1], *ptr[2]);

    read_string("\n\nPress enter to continue...");

    return 0;
}

void sort_two_strings(const char ** a, const char ** b) {

    int result = strcmp(*a, *b);

    if (result > 0) swap_strings(&(*a), &(*b));


}

void swap_strings(const char **a, const char **b) {

    const char *temp = *b;
    *b = *a;
    *a = temp;

}

void read_strings(const char * prompt, int amount, char *ptr[][100]) {

    const char * str;


    for (int i = 0; i < 3; i++) {

        *ptr[i] = malloc(100);
        str = read_string("type something: ");
        strcpy(*ptr[i], str);

    }


}
