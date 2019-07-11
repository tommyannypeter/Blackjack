#include <iostream>
#include <array>
#include "game.h"
#include "card.h"

int main() {
    std::array<Card, 52> deck;
    initialDeck(deck);

    char isContinue{'y'};
    do {
        shuffleDeck(deck);
        //for debug
        // std::cout << '\n';
        // printDeck(deck);
        // std::cout << '\n';

        switch (playBlackJack(deck)) {
            case Result::PLAYER_LOSE:
                std::cout << "You lose!" << '\n';
                break;
            case Result::DEALER_LOSE:
                std::cout << "You win!" << '\n';
                break;
            case Result::NEITHER_LOSE:
                std::cout << "Tie!" << '\n';
                break;
            default:
                std::cerr << "Unexpected error! -- from main()" << '\n';
                break;
        }

        do {
            std::cout << "Do you want to start a new game? (y/n)" << '\n';
            std::cin >> isContinue;
            std::cin.ignore(32767, '\n');
        } while ((isContinue != 'y') && (isContinue != 'n'));
        std::cout << '\n';
    } while (isContinue == 'y');

    return 0;
}
