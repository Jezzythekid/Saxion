#include <stdio.h>
#include "functions.h"
#include <math.h>

//opdracht 4, wisselgeld berekenen
float change;

int calculate(float donamination) {
    // calculating the amount of donamination coins the change is

    int amount_of_coins = 0;

    while (change >= donamination) {
        amount_of_coins = amount_of_coins + 1;
        change = change - donamination;
    }

    printf("You get back %d, %.2f euro coins.\n", amount_of_coins, donamination);
}

int main() {
    float price;
    float money_given;

    price = read_float("Please enter the price of the product:");
    money_given = read_float("please enter the amount of money that you pay");

    //edgecase: Not enough money
    if (money_given < price) {
        printf("Not enough money given\n");
        return 1;
    }

    //calculating: change
    change = money_given - price;
    printf("You get back %.2f euro. \n", change);

    //calculating the returncoins per donamination
    calculate(2.0);
    calculate(1.0);
    calculate(0.50);
    calculate(0.20);
    calculate(0.10);
    calculate(0.05);
    calculate(0.02);
    calculate(0.01);


    return 0;
}
