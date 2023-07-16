#pragma once

#include <iostream>

class Player {
public:
    Player(char marker) : marker(marker) {}

    int makeMove() const {
        int selectedColumn;
        std::cout << "Player " << marker << ": Enter column number (1 to 7): ";
        std::cin >> selectedColumn;
        return selectedColumn;
    }

    char getMarker() const {
        return marker;
    }

private:
    char marker;
};