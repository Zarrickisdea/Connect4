#pragma once

#include "board.hpp"
#include <memory>

class Game {
public:
    void start() {
        Board board;
        std::unique_ptr<Player> player1 = std::make_unique<Player>('X');
        std::unique_ptr<Player> player2 = std::make_unique<Player>('O');

        Player* currentPlayerPtr = nullptr;

        while (moves < rows * columns) {
            board.display();

            currentPlayerPtr = (currentPlayerPtr == player1.get()) ? player2.get() : player1.get();
            int selectedColumn = currentPlayerPtr->makeMove();

            if (board.placeMove(selectedColumn, currentPlayerPtr->getMarker())) {
                if (board.checkWin(currentPlayerPtr->getMarker())) {
                    board.display();
                    std::cout << "Player " << currentPlayerPtr->getMarker() << " wins!" << std::endl;
                    break;
                }

                // Switch to the other player for the next turn
                moves++;
            } else {
                std::cout << "Invalid move. Try again!" << std::endl;
            }
        }

        delete currentPlayerPtr;

        // If the grid is full and no one has won, it's a draw
        if (moves == rows * columns) {
            board.display();
            std::cout << "It's a draw!" << std::endl;
        }
    }

private:
    int moves = 0;
};
