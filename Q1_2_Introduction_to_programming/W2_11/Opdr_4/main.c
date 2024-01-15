#include <stdio.h>
#include "functions.h"

// Week 11, opdracht 4;
// Write a program that asks the user to enter a sentence, and then prints the frequency of each letter in the sentence.
// The program must ignore the case of the letters ,and must only count alphabetical characters.

/// Returns the frequency of each letter in the given sentence.
/// @param sentence The sentence to analyze.
/// @param frequencies An array of 26 integers, where the frequency of each letter is stored.
void get_letter_frequencies(const char * string, int frequencies[26]);

/// Returns the index of the letter with the highest frequency in the given array.
/// @param frequencies An array of 26 integers, where the frequency of each letter is stored.
/// @return The index of the letter with the highest frequency.
int get_highest_frequency_index(int frequencies[static 26]);

/// Prints the letter frequencies to the console. Modified the frequencies array by setting the frequency of each letter to zero after printing it.
/// @param frequencies An array of 26 integers, where the frequency of each letter is stored.
void print_letter_frequencies(int frequencies[static 26]);



const int ALPHABET_COUNT = 26;

int main(void) {

    const char * string;
    int letters[ALPHABET_COUNT] = {};

    string = read_string("Please enter a sentence:");

    get_letter_frequencies(string, letters);

    print_letter_frequencies(letters);

    printf("\n");

    return 0;
}

char lowAlphabet[26] = {"abcdefghijklmnopqrstuvwxyz"};
char capsAlphabet[26] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

void get_letter_frequencies(const char * string, int frequencies[26]) {

    for (int i = 0; string[i] != '\0'; i++) {

        for (int j = 0; j < ALPHABET_COUNT; j++) {

            if (string[i] == lowAlphabet[j] || string[i] == capsAlphabet[j]) {
                frequencies[j]++;
                break;
            }

        }

    }
}

int get_highest_frequency_index(int frequencies[static 26]) {

    int highestNumber = -1;
    int highestIndexNumber;

    for (int i = 0; i < ALPHABET_COUNT; i++) {

        if (frequencies[i] > highestNumber) {

            highestNumber = frequencies[i];
            highestIndexNumber = i;
        }
    }

    return highestIndexNumber;

}

void print_letter_frequencies(int frequencies[static 26]) {

    int highestIndex = get_highest_frequency_index(frequencies);

    for (int i = 0; i < ALPHABET_COUNT; i++) {

        if (frequencies[highestIndex] == 0) break;

        printf("%c: %d\n", lowAlphabet[highestIndex], frequencies[highestIndex]);

        frequencies[highestIndex] = -1;

        highestIndex = get_highest_frequency_index(frequencies);

    }

}