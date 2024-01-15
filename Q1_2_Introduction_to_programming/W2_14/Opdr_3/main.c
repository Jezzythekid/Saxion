#include <stdio.h>
#include "functions.h"
#include "types.h"

typedef struct {
    rank_t rank;
    suit_t suit;
} card_t;

const int DECK_SIZE = 52;

/// Builds a deck of 52 playing cards.
/// @param deck The array to fill with cards.
void build_deck(card_t deck[static DECK_SIZE]);

/// Prints a playing card to the console.
/// @param card The card to print.
void print_card(const card_t *card);

/// Checks if the player has won the higher/lower game.
/// @param current the card visible to the player.
/// @param next the card of witch the player must guess higher or lower
/// @param inp the input of the player 'h' = higher, 'l' = lower.
/// @return true = won, false = incorrect.
bool check_if_won(card_t *current, card_t *next, char inp);

/// Plays a game of higher and lower with a deck of cards
/// @param deck the deck of cards to play with
/// @return the number of round played before winning
int higher_or_lower(card_t deck[52]);

int main() {

    // init variables
    card_t deck[52];
    int noOfRounds;

    // fill deck with shuffled cards
    build_deck(deck);

    // run the game and return the rounds it took
    noOfRounds = higher_or_lower(deck);

    // print result of the game
    printf("\n\nGame over after %d cards", noOfRounds);


    read_string("\n\nPress enter to exit...");

    return 0;
}

void build_deck(card_t deck[static DECK_SIZE]) {

/*    for (int i = 0; i < DECK_SIZE; i++) {

        deck[i].rank = random_int(2, ACE);
        deck[i].suit = random_int(HEARTS, CLUBS);

    }
    */
    int i = 0;

    for (suit_t suit = HEARTS; suit <= CLUBS; ++suit) {
        for (rank_t rank = 2; rank <= ACE; ++rank) {

            deck[i].rank = rank;
            deck[i].suit = suit;
            i++;
        }
    }
    shuffle(deck, DECK_SIZE, sizeof(card_t));
}

void print_card(const card_t *card) {

    static bool isFirstCard = true;

    const char * rank = rank_type_to_string(card->rank);
    const char * suit = suit_type_to_string(card->suit);

    if (isFirstCard) {
        printf("The first card is the %s of %s", rank, suit);
        isFirstCard = false;
    }
    else printf("The next card is the %s of %s", rank, suit);

}

bool check_if_won(card_t *current, card_t *next, char inp) {

    if (next->rank >= current->rank && inp == 'h') return true;
    if (next->rank <= current->rank && inp == 'l') return true;

    // else
    return false;

}

int higher_or_lower(card_t deck[52]) {

    int count = -1;
    char inp;
    bool playerWon = false;

    do {

        count++;

        // check if deck is empty
        if (count >= 51) {

            printf("\nThe deck is empty, game over *cough cough* loser *cough* ");
            return 52;
        }

        print_card(&deck[count]);

        inp = read_char("\nWill the next card be higher (h) or lower (l)? ");

        // Check if character is in bounds
        while (inp != 'h' && inp != 'l') {
            inp = read_char("\ninvalid character! \nWill the next card be higher (h) or lower (l)? ");
        }

        playerWon = check_if_won(&deck[count], &deck[count + 1], inp);


    } while (playerWon);

    print_card(&deck[count + 1]);

    return count + 1;
}