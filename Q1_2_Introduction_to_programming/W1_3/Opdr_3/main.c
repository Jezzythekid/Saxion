#include <stdio.h>
#include "functions.h"

// Week 3 Opdacht 3, rock paper scissors from week 2 with added while statement to play multiple
// round. program will also keep count and print the score when the player enters 'q' to end the
// game.

// Functions runs when player selects rock

char player_rock(int computer) {

    char winner;

    switch(computer) {
        case 1:
            printf("\nI choose rock.\nIt's a tie!\n");
            winner = 't';
            break;

        case 2:
            printf("\nI choose paper.\nI win!\n");
            winner = 'c';
            break;

        case 3:
            printf("\nI choose scissors.\nYou win!\n");
            winner = 'p';
            break;
    }
    return winner;
}

// Functions runs when player selects paper

char player_paper(int computer) {

    char winner;

    switch(computer) {
        case 1:
            printf("\nI choose rock.\nYou win!\n");
            winner = 'p';
            break;

        case 2:
            printf("\nI choose paper.\nIt's a tie!\n");
            winner = 't';
            break;

        case 3:
            printf("\nI choose scissors.\nI win!\n");
            winner = 'c';
            break;
    }
    return winner;
}

// Functions runs when player selects scissors

char player_scissors(int computer) {

    char winner;

    switch(computer) {
        case 1:
            printf("\nI choose rock.\nI win!\n");
            winner = 'c';
            break;

        case 2:
            printf("\nI choose paper.\nYou win!\n");
            winner = 'p';
            break;

        case 3:
            printf("\nI choose scissors.\nIt's a tie!\n");
            winner = 't';
            break;
    }
    return winner;
}

// Functions to let the player

char rock_paper_siccors(int cpu, char userInput) {

    char winner;

    switch(userInput) {
        case 'r': //rock
            printf("\nYou chose rock.\n");
            winner = player_rock(cpu);
            break;

        case 'p': //paper
            printf("\nYou chose paper.\n");
            winner = player_paper(cpu);
            break;

        case 's': //scissors
            printf("\nYou chose scissors.\n");
            winner = player_scissors(cpu);
            break;

        case 'q': //quit
            winner = 't';
            break;

        default:
            printf("\nInvalid choice.\n");
            winner = 't';
    }

    return winner;

}

int main() {

    char userInput;
    int userInputToInt;
    int computer;
    char winner;
    int pointsPlayer = 0;
    int pointsComputer = 0;

    userInput = read_char("Please enter your choice (r = rock, p = paper, s = scissors):\n");


    while (userInput != 'q') {
        computer = random_int(1,3);

        winner = rock_paper_siccors(computer, userInput);

        if (winner == 'p') pointsPlayer = pointsPlayer + 1;
        if (winner == 'c') pointsComputer = pointsComputer + 1;

        printf("\nPoints player: %d\nPoints computer: %d\n\n", pointsPlayer, pointsComputer);
        userInput = read_char("Please enter your choice (r = rock, p = paper, s = scissors):\n");
    }

    printf("Game ended\nScore: player %d, computer %d", pointsPlayer, pointsComputer);


    return 0;
}


