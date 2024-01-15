#include <stdio.h>
#include <string.h>
#include "functions.h"
#include "ctype.h"

// Week 13, opdracht 4:
// Write a program that lets the user enter a sentence, and then prints the sentence in which each word
// is reversed. Note that the characters of each word are reversed individually, but the order
// of the words is not changed. The program must repeat this process until the user enters an empty
// sentence

/// Function to swap two characters in a string
/// @param a first character to swap
/// @param b second character to swap
void swap(char * a, char * b);

/// Starting with position, finds the first character that
/// is printable and not whitespace or punctuation.
/// @param position the address at which the search is started
/// @returns the address of the first word-character, or NULL if no
///   such character could be found.
char *find_first_word_character(char *position);

/// Starting with position, finds the first character that
/// is whitespace, punctuation, or non-printable.
/// @param position the address at which the search is started
/// @returns the address of the first non-word-character, or NULL if no
///   such character could be found.
char *find_first_non_word_character(char *position);

/// Reverses the characters in the string starting and ending at the given positions.
/// @param begin the address at which the string to be reversed starts
/// @param end the address at which the string to be reversed ends
void reverse_string(char *begin, char *end);

/// Checks if a string is empty (i.e., consists only of whitespace).
/// @param string the string to check
/// @returns true if the string is empty, false otherwise.
bool is_empty(const char *string);

int main() {

    // copy the const char read_string, to a char array
    const char * inp;
    char str[50];

    inp = read_string("Please enter a string: ");
    strcpy(str, inp);

    // While loop that keeps checking if the sentence is empty, quits if that's the case
    while (!is_empty(str)) {

        char *idx_start = NULL;
        const char *idx_end = str;

        // do-while loop keeps checking if the idx_start != NULL, indicating that the end of the string is reached
        do {
            // find the first printable character (the start of a word)
            // and store the index in a variable
            idx_start = find_first_word_character(idx_end);

            // if idx_start == NULL, het end of the string has been reached
            if (idx_start == NULL) break;

            // find the first non-printable character (end of the word)
            idx_end = find_first_non_word_character(idx_start);

            // swap the characters in the word in pairs of two (1. first and last, 2. second and second to last, etc.)
            // if index start != NULL stop swapping
            reverse_string(idx_start, idx_end);

        }
        while (idx_start != NULL);

        printf("\nflipped: %s\n", str);

        inp = read_string("\nPress enter to exit, or enter another string: ");
        strcpy(str, inp);


    }

    return 0;
}

char *find_first_word_character(char *position) {

    // loop through the characters in a string, until the value = '\0' indicating the end of the string.
    for (int i = 0; position[i] != '\0'; i++) {

        // if a word-character is found, return its address.
        if (isalpha(position[i]) != 0) {
            return &position[i];
        }

    }

    // if a word-character isn't found return a NULL-pointer
    return NULL;

}

char *find_first_non_word_character(char *position){

    int idx_end = 0;

    // loop through the characters in a string, until the value = '\0' indicating the end of the string.
    for (int i = 0; position[i] != '\0'; i++) {

        // if a non-word-character is found, return its address.
        if (isalpha(position[i]) == 0) {
            return &position[i];
        }

        idx_end++;
    }

    // if it isn't found return the address of the character before the '\0'
    return &position[idx_end];


}


// to reverse a string, we first swap the outer two characters, and move in by one and swap again.
void reverse_string(char *begin, char *end) {

    int countBegin = 0;
    int countEnd = -1; // offset the end by -1

    // loops until the pointers cross
    while (&begin[countBegin] <= &end[countEnd]) {

        // swap the characters
        swap(&begin[countBegin], &end[countEnd]);

        // move the pointer "begin" forwards
        countBegin++;
        // move the pointer "end" backwards
        countEnd--;

    }


}

bool is_empty(const char *string) {


    // checks is the value == '\' indicating it's empty
    if (*string == '\0') return true;

    return false;

}

void swap(char * a, char * b) {

    // swaps the values that the pointers point to

    char temp = *a;
    *a = *b;
    *b = temp;

}