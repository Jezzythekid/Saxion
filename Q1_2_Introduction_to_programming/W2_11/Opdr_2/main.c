#include <stdio.h>
#include <string.h>
#include "functions.h"
#include "ctype.h"

// Week 11, opdracht 2;
// Write a program that asks the user to enter a sentence, and then encodes the sentence by shifting each character in a specific way.
// The program then prints the encoded sentence, decodes it again, and prints the result of the decoding.

/// function to increment a character to the next valid character.
/// in this case only alphabetical lower and caps are valid.
/// @param character the character to be incremented.
/// @param amount amount to increase the character with
/// @return the incremented character.
int incrementCharacter(char character, int amount);

/// function to decrease a character to the next valid character.
/// in this case only alphabetical lower and caps are valid.
/// @param character the character to be decreased.
/// @param amount amount to decrease the character with
/// @return the decreased character.
int decreaseCharacter(char character, int amount);

const int ALPHA_AMOUNT = 26;

int main(void) {
    const char *message = read_string("type message:");
    printf("Raw:\n %s\nEncrypted:\n ", message);

    char encrypted[106];
    int charAmount = 0;

    // encrypt
    for (int i = 0; message[i] != '\0'; i++) {
        encrypted[i] = incrementCharacter(message[i], i+1);

        printf("%c", encrypted[i]);

        charAmount++;
    }

    printf("\nDecrypted:\n ");

    // decrypt
    for (int i = 0; message[i] != '\0'; i++) {
        encrypted[i] = decreaseCharacter(encrypted[i], i+1);

        printf("%c", encrypted[i]);
    }

    return 0;
}

char alphabet[58] = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};

int incrementCharacter(char character, int amount) {

    // modulo ALPHA_AMOUNT gives the wraparound values
    // character - 'A' gives the indexValue in the alphabet
    // then the program needs to add the ASCII offset again with the 'A' +

    if (isupper(character)) {
        return alphabet[(character - 'A' + amount + ALPHA_AMOUNT) % (ALPHA_AMOUNT*2)];
    }

    if (islower(character)) {
        return alphabet[(character - 'a' + amount) % (ALPHA_AMOUNT*2)];
    }

    return character;
}

// reversed alphabet user in decreaseCharacter function.

//char capsRevAlphabet[26] = {"ZYXWVUTSRQPONMLKJIHGFEDCBA"};
//char lowRevAlphabet[26] = {"zyxwvutsrqponmlkjihgfedcba"};
char revAlphabet[58] = {"zyxwvutsrqponmlkjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA"};

int decreaseCharacter(char character, int amount) {

    // modulo ALPHA_AMOUNT gives the wraparound values
    // 'X' - character gives the index in the capsRevAlphabet (or lowRevAlphabet)
    // then the software adds the increase amount and returns the character.

    if (isupper(character)) {

        return revAlphabet[('Z' - character + amount + ALPHA_AMOUNT) % (ALPHA_AMOUNT*2)];

    }

    if (islower(character)) {

        return revAlphabet[('z' - character + amount) % (ALPHA_AMOUNT*2)];

    }

    return character;
}