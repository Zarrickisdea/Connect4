#pragma once

#include <iostream>
#include <limits>

class Player {
public:
    Player(char marker) : marker(marker) {}

    int makeMove() const {
        int selectedColumn;
        while (true) {
            std::cout << "Player " << marker << ":" << std::endl << "Enter column number (1 to 7): ";

            if (std::cin >> selectedColumn) {
                // Check if the input is within the valid range (1 to 7)
                if (selectedColumn >= 1 && selectedColumn <= 7) {
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    return selectedColumn;
                } else {
                    std::cout << "Invalid column number. Please enter a number between 1 and 7." << std::endl;
                }
            } else {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a number between 1 and 7." << std::endl;
            }
        }
    }

    char getMarker() const { return marker; }

private:
    char marker;
};