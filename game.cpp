#include "game.h"
#include "card.h"
#include <array>
#include <iostream>

Result playBlackJack(const std::array<Card, 52> &deck) {
    const Card *cardPtr{&deck[0]};
    int playerScore{0};
    int dealerScore{0};

    //dealer gets one card and player gets two cards to start
    dealerScore += getCardValue(*cardPtr++, dealerScore);
    playerScore += getCardValue(*cardPtr++, playerScore);
    playerScore += getCardValue(*cardPtr++, playerScore);

    //player's turn
    do {
        Result bust{isBust(dealerScore, playerScore)};
        if (bust != Result::NEITHER_LOSE) return bust;
        char standOrHit{getChoice()};
        if (standOrHit == 's') break;
        else playerScore += getCardValue(*cardPtr++, playerScore);
    } while (true);

    //dealer's turn
    do {
        if (dealerScore < 17) {
            dealerScore += getCardValue(*cardPtr++, dealerScore);
        }
        else break;
    } while (true);
    return isOver(dealerScore, playerScore);
}

void showScore(int dealerScore, int playerScore) {
    std::cout << "The dealer's score: " << dealerScore << '\n';
    std::cout << "The player's score: " << playerScore << '\n';
}

Result isBust(int dealerScore, int playerScore) {
    showScore(dealerScore, playerScore);
    if ((dealerScore > 21) && (playerScore > 21)) return Result::PLAYER_LOSE;
    else if (playerScore > 21) return Result::PLAYER_LOSE;
    else if (dealerScore > 21) return Result::DEALER_LOSE;
    else return Result::NEITHER_LOSE;
}

Result isOver(int dealerScore, int playerScore) {
    Result bust{isBust(dealerScore, playerScore)};
    if (bust != Result::NEITHER_LOSE) return bust;
    else if (dealerScore == playerScore) return Result::NEITHER_LOSE;
    else if (dealerScore > playerScore) return Result::PLAYER_LOSE;
    else if (dealerScore < playerScore) return Result::DEALER_LOSE;
}

char getChoice() {
    char standOrHit{'0'};
    do {
        std::cout << "Do you want to stand or hit? (s/h) ";
        std::cin >> standOrHit;
        std::cin.ignore(32767, '\n');
    } while ((standOrHit != 's') && (standOrHit != 'h'));
    return standOrHit;
}
