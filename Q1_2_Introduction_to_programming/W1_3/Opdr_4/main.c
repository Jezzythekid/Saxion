#include <stdio.h>
#include "functions.h"
#include "stdbool.h"

// Week 3 opdracht 4: Pretzel game: user plays agains the cpu.
// Players take turns removing pretzels from a pile of pretzels.
// Each player can remove 1, 2 or 3 pretzels. The player that removes the last pretzel loses the game.


int ComputersTurn(void) {

    int amountOfPretzels;

    amountOfPretzels = random_int(1, 3);


}


int main(void) {

    int rng;
    int player;
    int pileSize;
    int coinflip;



    printf("\nWelcome to the pretzel game\n");
    pileSize = read_int("How many pretzels are in the pile?");
    printf("I'll flip a coin to see who starts");

    coinflip = random_int(0, 1); // 0: user 1:cpu

    //if (coinflip == 1) WIP





    player = read_int("How many pretzels do you want to remove? ");

    rng = random_int(1, 3);

    return 0;
}


