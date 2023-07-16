#pragma once

#include "board.hpp"
#include <memory>


class Game {
public:
  void printRules() const {
    std::cout << "Welcome to Connect 4!\n";
    std::cout << "Rules:\n";
    std::cout << "1. Players take turns to place their marker ('X' or 'O') in "
                 "a column.\n";
    std::cout << "2. The first player to get four markers in a row, column, or "
                 "diagonal wins.\n";
    std::cout
        << "3. The game ends in a draw if the board is full with no winner.\n";
    std::cout << std::endl;
  }

  void waitForStart() const {
    std::cout << "Press Enter to start the game...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  void start() {
    printRules();
    waitForStart();

    Board board;
    std::unique_ptr<Player> player1 = std::make_unique<Player>('R');
    std::unique_ptr<Player> player2 = std::make_unique<Player>('Y');

    Player *currentPlayerPtr = nullptr;

    while (moves < rows * columns) {
      board.display();

      currentPlayerPtr =
          (currentPlayerPtr == player1.get()) ? player2.get() : player1.get();
      int selectedColumn = currentPlayerPtr->makeMove();

      if (board.placeMove(selectedColumn, currentPlayerPtr->getMarker())) {
        if (board.checkWin(currentPlayerPtr->getMarker())) {
          board.display();
          std::cout << "Player " << currentPlayerPtr->getMarker() << " wins!"
                    << std::endl;
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
