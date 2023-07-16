#pragma once

#include <string>
#include "player.hpp"


const int rows = 6;
const int columns = 7;

class Board {
public:
    Board() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                grid[i][j] = ' '; // Initialize the grid with spaces
            }
        }
    }

    void display() const {
        std::cout << "-----------------------------" << std::endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                std::cout << "| " << grid[i][j] << " ";
            }
            std::cout << "|" << std::endl;
            std::cout << "-----------------------------" << std::endl;
        }
    }

    bool placeMove(int selectedColumn, char player) {
        // Convert column number to array index (0 to 6)
        selectedColumn--;

        // Check if the selected column is valid
        if (selectedColumn < 0 || selectedColumn >= columns || grid[0][selectedColumn] != ' ') {
            return false; // Invalid move
        }

        // Place the player's move in the grid
        int row;
        for (row = rows - 1; row >= 0; row--) {
            if (grid[row][selectedColumn] == ' ') {
                grid[row][selectedColumn] = player;
                return true; // Move placed successfully
            }
        }

        return false; // Column is full
    }

bool checkWin(char player) {
  // Horizontal win check
    for (int i = 0; i < rows; i++) {
        std::string rowStr;
        for (int j = 0; j < columns; j++) {
            rowStr.push_back(grid[i][j]);
        }
        std::string target(4, player);
        if (rowStr.find(target) != std::string::npos) {
            return true;
        }
    }

  // Vertical win check
    for (int j = 0; j < columns; j++) {
        std::string columnStr;
        for (int i = 0; i < rows; i++) {
            columnStr.push_back(grid[i][j]);
        }
        std::string target(4, player);
        if (columnStr.find(target) != std::string::npos) {
            return true;
        }
    }

    // Diagonal win check
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (grid[i][j] == player) {

                if (i + 3 < rows && j + 3 < columns &&
                    grid[i + 1][j + 1] == player &&
                    grid[i + 2][j + 2] == player &&
                    grid[i + 3][j + 3] == player) {
                    return true;
                }


                if (i - 3 >= 0 && j + 3 < columns &&
                    grid[i - 1][j + 1] == player &&
                    grid[i - 2][j + 2] == player &&
                    grid[i - 3][j + 3] == player) {
                    return true;
                }
            }
        }
    }

    return false;
}

private:
    char grid[rows][columns];
};