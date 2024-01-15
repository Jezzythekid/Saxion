//
// Created by Eigenaar on 22-12-2023.
//

#include "types.h"


const char *suit_type_to_string(suit_t  type) {
    switch (type) {
        case HEARTS:
            return "Hearts";
        case DIAMONDS:
            return  "Diamonds";
        case SPADES:
            return  "Spades";
        case CLUBS:
            return  "Clubs";
        default:
            return "INVALID";
    }
}

const char *rank_type_to_string(rank_t  type) {

    switch (type) {
        case 1:
            return "1";
        case 2:
            return "2";
        case 3:
            return "3";
        case 4:
            return "4";
        case 5:
            return "5";
        case 6:
            return "6";
        case 7:
            return "7";
        case 8:
            return "8";
        case 9:
            return "9";
        case 10:
            return "10";
        case JACK:
            return "Jack";
        case QUEEN:
            return  "Queen";
        case KING:
            return "King";
        case ACE:
            return "Ace";
        default:
            return "INVALID";
    }
}