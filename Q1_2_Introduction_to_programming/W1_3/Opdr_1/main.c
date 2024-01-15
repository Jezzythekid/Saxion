#include <stdio.h>
#include "functions.h"
#include "stdbool.h"

// Week 3 Opdracht 1: let the user guess a number form 0 - 100.
// Program will give hint when the guess is too high or too low.

int main() {
    int rnd;
    int guess = -1;
    int guesses = 1;

    rnd = random_int(0, 100);

    guess = read_int("I'm thinking of a number between 0 and 100\nGuess the number: ");

    while (guess != rnd) {

        if (guess < rnd) guess = read_int("Too low!\nGuess the number: ");
        else if (guess > rnd) guess = read_int("Too high!\nGuess the number: ");

        guesses++;
    }

    printf("Correct it took you %d guesses", guesses);

}
