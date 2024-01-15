#include <stdio.h>
#include <ctype.h>
#include "functions.h"
#include "string.h"

// Week 13, opdracht 3
// Write a program that asks the user to enter two strings,
// and then prints whether the two strings are anagrams of each other.

/// Returns the frequency of each letter in the given sentence.
/// @param sentence The sentence to analyze.
/// @param frequencies An array of 26 integers, where the frequency of each letter is stored.
void get_letter_frequencies(const char * string, int frequencies[26]);

/// Function that asks the user to enter sentences
/// @param amount amount of sentences to ask for.
/// @param arr the array to write to.
/// @param prompt the prompt to print in the terminal.
void read_sentences(int amount, char arr[][50], const char * prompt);

/// Returns true if the two given strings are anagrams of each other.
/// @param string1 the first string
/// @param string2 the second string
/// @returns true if the two strings are anagrams of each other, false otherwise.
bool are_anagrams(const char *string1, const char *string2);


/// Returns true if the two arrays are the same
/// @param arr1 the first array
/// @param arr2 the second array
/// @param size the size of the two arrays
/// @return true if the tro arrays are the same
bool compare_arrays(int *arr1, int *arr2, int size);

const int ALPHABET_COUNT = 26;

int main(void) {
    char strings[2][50];

    // Ask the user for sentences
    read_sentences(2, strings, "please enter a string: ");

    // check if strings are anagrams
    if (are_anagrams(strings[0], strings[1])) {

        printf("\n'%s', '%s' are anagrams", strings[0], strings[1]);

    } else {

        printf("\n'%s', '%s' are not anagrams", strings[0], strings[1]);

    }

/*
    printf("\n'%s', '%s' are %s anagrams", strings[0], strings[1],
           are_anagrams(strings[0], strings[1]) ? "" : "not");
*/


    read_string("\n\nPress enter to continue...");

    return 0;
}

void read_sentences(int amount, char arr[][50], const char * prompt) {

    const char * buff;

    for (int i = 0; i < amount; i++) {

        buff = read_string(prompt);
        strcpy(arr[i], buff);

    }
}

char lowAlphabet[26] = {"abcdefghijklmnopqrstuvwxyz"};
char capsAlphabet[26] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

void get_letter_frequencies(const char * string, int frequencies[26]) {

    for (int i = 0; string[i] != '\0'; i++) {
        char c = string[i];
        if (isalpha(c))
        {
            frequencies[tolower(c) - 'a']++;
        }

/*        for (int j = 0; j < ALPHABET_COUNT; j++) {

            if (string[i] == lowAlphabet[j] || string[i] == capsAlphabet[j]) {
                frequencies[j]++;
                break;
            }

        }*/

    }
}

bool are_anagrams(const char *string1, const char *string2) {

    int NoOfLetters[2][26] = {0};

    // count the number of letters in the string
    get_letter_frequencies(string1, NoOfLetters[0]);
    get_letter_frequencies(string2, NoOfLetters[1]);

    return compare_arrays(NoOfLetters[0], NoOfLetters[1], 26);


}

bool compare_arrays(int *arr1, int *arr2, int size) {

    for (int i = 0; i < size; i++) {

        if (arr1[i] != arr2[i]) return false;

    }

    return true;

}