#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

// ====================================================================================================
// Week 4 opdracht 4: Treasure hunt:
// Write a program that lets the user find a treasure that is hidden in a grid of 9 rows by 9 columns.
// The program must first randomly place the treasure in one of the squares of the grid
// The program must then ask the user to enter a row and a column,
// and must tell the user whether the treasure is hidden in that square or not.
// the user must not be allowed to enter a row or column that is outside the grid
// ====================================================================================================

const short int SIZE = 9;   //not configurable because offset 2-digit numbers
//char map[SIZE][SIZE];


int rowGuess[81] = {};
int colGuess[81] = {};

int rowTreasure;
int colTreasure;


// Function printCharacter() prints the correct character on the map
// '.' for grid, 'X' for treasure, '+' for prev. attempts.
// This is done by checking the arrays for the previous attempted coordinates.
int printCharacter(int attempt, int row, int col) {

    for (int i = 0; i <= attempt; i++) {

        if (rowGuess[i] == row && colGuess[i] == col) {

            if (row == rowTreasure && col == colTreasure) printf("X ");
            else printf("+ ");
            break;
        }
        if (i == attempt) printf(". ");
    }

    return 0;
}


// Function generates the field on which the treasure is hidden
// each row (i) will print 9 columns (j)
int generateField(int attempt) {

    printf("\n   1 2 3 4 5 6 7 8 9\n");
    for (int i = 1; i <= SIZE; i++) {
        printf(" %d ", i);
        for (int j = 1; j <= SIZE; j++) {
            printCharacter(attempt, i, j);
        }
        printf("\n");
    }
    printf("\n");

    // Formula gifted from teacher
    int distance = max(rowTreasure - rowGuess[attempt], rowGuess[attempt] - rowTreasure) +
                   max(colTreasure - colGuess[attempt], colGuess[attempt] - colTreasure);

    printf("Distance from treasure = %d.\n", distance);

    return 0;
}

int main(void) {

    int userInputRow = 0;
    int userInputCol = 0;
    int guessNo = 0;

    rowTreasure = random_int(1, 9);
    colTreasure = random_int(1, 9);

    system("cls");  //clears the powershell terminal

    while (userInputCol != colTreasure || userInputRow != rowTreasure) {

        userInputRow = read_int("\nSelect row\n");
        userInputCol = read_int("Select column\n");

        // edge case: out of bounds coordinate
        if ((userInputCol > SIZE || userInputCol < 1) ||
            (userInputRow > SIZE || userInputRow < 1))
        {
            printf("\nEntered coordinate not in range (1-9)\n");
            return 404; //brain not found
        }

        rowGuess[guessNo] = userInputRow;
        colGuess[guessNo] = userInputCol;


        generateField(guessNo);

        guessNo++;
    }

    printf("\nTreasure found!\n\nIt took you %d attempts!\n\n", guessNo);

    return 0;
}


