#include "card.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

void printCard(const Card &card) {
    char rank{'0'};
    switch (card.rank) {
        case Rank::TWO:
            rank = '2';
            break;
        case Rank::THREE:
            rank = '3';
            break;
        case Rank::FOUR:
            rank = '4';
            break;
        case Rank::FIVE:
            rank = '5';
            break;
        case Rank::SIX:
            rank = '6';
            break;
        case Rank::SEVEN:
            rank = '7';
            break;
        case Rank::EIGHT:
            rank = '8';
            break;
        case Rank::NINE:
            rank = '9';
            break;
        case Rank::TEN:
            rank = 'T';
            break;
        case Rank::JACK:
            rank = 'J';
            break;
        case Rank::QUEEN:
            rank = 'Q';
            break;
        case Rank::KING:
            rank = 'K';
            break;
        case Rank::ACE:
            rank = 'A';
            break;
        default:
            rank = '0';
            break;
    }
    char suit{'0'};
    switch (card.suit) {
        case Suit::CLUBS:
            suit = 'C';
            break;
        case Suit::DIAMONDS:
            suit = 'D';
            break;
        case Suit::HEARTS:
            suit = 'H';
            break;
        case Suit::SPADES:
            suit = 'S';
            break;
        default:
            suit = '0';
            break;
    }
    std::cout << rank << suit;
}

void initialDeck(std::array<Card, 52> &deck) {
    for (int rankIndex{0}; rankIndex < 13; ++rankIndex) {
        for (int suitIndex{0}; suitIndex < 4; ++suitIndex) {
            deck[suitIndex * 13 + rankIndex].rank = static_cast<Rank>(rankIndex + 1);
            deck[suitIndex * 13 + rankIndex].suit = static_cast<Suit>(suitIndex);
        }
    }
}

void printDeck(const std::array<Card, 52> &deck) {
    for (const Card &card : deck) {
        printCard(card);
        std::cout << " ";
    }
    std::cout << '\n';
}

void swapCard(Card &card1, Card &card2) {
    Card cardTemp = card1;
    card1 = card2;
    card2 = cardTemp;
}

void shuffleDeck(std::array<Card, 52> &deck) {
    const int max{51};
    const int min{0};
    int randNum{0};
    std::srand(static_cast<unsigned int>(std::time(0)));
    static const double fraction = 1.0 / (RAND_MAX + 1.0);
    for (int cardIndex{0}; cardIndex < 52; ++cardIndex) {
        randNum = min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
        swapCard(deck[cardIndex], deck[randNum]);
    }
}

int getCardValue(const Card &card, int score) {
    if ((card.rank == Rank::ACE) && (score > 10)) return 1;
    switch (card.rank) {
        case Rank::TWO:
        case Rank::THREE:
        case Rank::FOUR:
        case Rank::FIVE:
        case Rank::SIX:
        case Rank::SEVEN:
        case Rank::EIGHT:
        case Rank::NINE:
            return static_cast<int>(card.rank);
        case Rank::TEN:
        case Rank::JACK:
        case Rank::QUEEN:
        case Rank::KING:
            return 10;
        case Rank::ACE:
            return 11;
        default:
            return 0;
    }
}
