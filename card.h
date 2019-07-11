#ifndef CARD_H
#define CARD_H

#include <array>

enum class Rank {
    TWO = 2,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE = 1,
    RANK_DEFAULT = 0
};

enum class Suit {
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES,
    SUIT_DEFAULT
};

struct Card {
    Rank rank;
    Suit suit;
};

void printCard(const Card &card);
void initialDeck(std::array<Card, 52> &deck);
void printDeck(const std::array<Card, 52> &deck);
void swapCard(Card &card1, Card &card2);
void shuffleDeck(std::array<Card, 52> &deck);
int getCardValue(const Card &card, int score);

#endif
