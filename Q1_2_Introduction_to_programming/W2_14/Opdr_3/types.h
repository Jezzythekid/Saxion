//
// Created by Eigenaar on 22-12-2023.
//

#ifndef OPDR_3_TYPES_H
#define OPDR_3_TYPES_H

typedef enum suit_t {
    HEARTS = 0,
    DIAMONDS = 1,
    SPADES = 2,
    CLUBS = 3
} suit_t;

typedef enum rank_t {
    JACK = 11,
    QUEEN = 12,
    KING = 13,
    ACE = 14
} rank_t;


/// function that returns the name of the string representation
/// @param type the type to get the string representation of
/// @return the string representation
const char *suit_type_to_string(suit_t  type);

/// function that returns the name of the string representation
/// @param type the type to get the string representation of
/// @return the string representation
const char *rank_type_to_string(rank_t  type);

#endif //OPDR_3_TYPES_H
