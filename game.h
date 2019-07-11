#ifndef GAME_H
#define GAME_H

#include <array>
#include "card.h"

enum class Result {
    PLAYER_LOSE,
    DEALER_LOSE,
    NEITHER_LOSE
};

Result playBlackJack(const std::array<Card, 52> &deck);
void showScore(int dealerScore, int playerScore);
Result isBust(int dealerScore, int playerScore);
Result isOver(int dealerSocre, int playerScore);
char getChoice();

#endif
