#include <stdio.h>
#include "functions.h"

//Opdacht 1, berekenen van de oppervlakte:

int player_rock(int computer) {

    switch(computer) {
        case 1:
            printf("I choose rock.\nIt's a tie!");
            break;

        case 2:
            printf("I choose paper.\nI win!");
            break;

        case 3:
            printf("I choose scissors.\nYou win!");
            break;
    }
    return 0;
}

int player_paper(int computer) {

    switch(computer) {
        case 1:
            printf("I choose rock.\nYou win!");
            break;

        case 2:
            printf("I choose paper.\nIt's a tie!");
            break;

        case 3:
            printf("I choose scissors.\nI win!");
            break;
    }
    return 0;
}

int player_scissors(int computer) {

    switch(computer) {
        case 1:
            printf("I choose rock.\nI win!");
            break;

        case 2:
            printf("I choose paper.\nYou win!");
            break;

        case 3:
            printf("I choose scissors.\nIt's a tie!");
            break;
    }
    return 0;
}

int main() {

    char userInput;
    int userInputToInt;
    int computer;

    userInput = read_char("Please enter your choice (r = rock, p = paper, s = scissors):\n");
    computer = random_int(1,3);

    switch(userInput) {
        case 'r': //rock
            userInputToInt = 1;
            printf("You chose rock.\n");
            player_rock(computer);
            break;

        case 'p': //paper
            userInputToInt = 2;
            printf("You chose paper.\n");
            player_paper(computer);
            break;

        case 's': //scissors
            userInputToInt = 3;
            printf("You chose scissors.\n");
            player_scissors(computer);
            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}


