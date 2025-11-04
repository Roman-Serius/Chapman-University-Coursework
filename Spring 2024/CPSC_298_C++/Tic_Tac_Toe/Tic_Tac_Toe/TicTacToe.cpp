//
//  TicTacToe.cpp
//  Tic_Tac_Toe
//
//  Created by Soren on 5/9/24.
//

#include <iostream>
#include "TicTacToe.h"

TicTacToe::TicTacToe() {
    rows = 3;
    cols = 3;
    // Allocate grid dynamically
    grid = new char*[rows];
    for (int i = 0; i < rows; ++i) {
        grid[i] = new char[cols];
    }
    initializeGrid();
}

TicTacToe::~TicTacToe() {
    // Deallocate the dynamically allocated grid
    for (int i = 0; i < rows; ++i) {
        delete[] grid[i];
    }
    delete[] grid;
}

void TicTacToe::initializeGrid() {
    // Fill the grid with '~'
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            grid[i][j] = '~';
        }
    }
}

bool TicTacToe::isWin(char player) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < rows; ++i) {
        if (grid[i][0] == player && grid[i][1] == player && grid[i][2] == player)
            return true;
    }
    for (int i = 0; i < cols; ++i) {
        if (grid[0][i] == player && grid[1][i] == player && grid[2][i] == player)
            return true;
    }
    if (grid[0][0] == player && grid[1][1] == player && grid[2][2] == player)
        return true;
    if (grid[0][2] == player && grid[1][1] == player && grid[2][0] == player)
        return true;

    return false;
}

bool TicTacToe::isDraw() {
    // If there are no empty cells, and no player won, it's a draw
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == '~')
                return false;
        }
    }
    return true;
}

void TicTacToe::displayGrid() {
    // Print the current state of the grid
    std::cout << "\nCurrent Grid:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void TicTacToe::getPlayerMove() {
    int row, col;
    while (true) {
        std::cout << "\nEnter your move (row and column 0, 1, 2): ";
        std::cin >> row >> col;

        // Validate input
        if (row >= 0 && row < rows && col >= 0 && col < cols && grid[row][col] == '~') {
            grid[row][col] = 'X';
            break;
        } else {
            std::cout << "Invalid move, please try again.";
        }
    }
}

void TicTacToe::getComputerMove() {
    // Simple AI: choose the next available empty cell
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == '~') {
                grid[i][j] = 'O';
                return;
            }
        }
    }
}

void TicTacToe::play() {
    displayGrid();
    while (true) {
        getPlayerMove();
        displayGrid();
        if (isWin('X')) {
            std::cout << "\nCongratulations! You win!\n";
            break;
        }
        if (isDraw()) {
            std::cout << "\nIt's a draw!\n";
            break;
        }

        getComputerMove();
        displayGrid();
        if (isWin('O')) {
            std::cout << "\nComputer wins. Better luck next time!\n";
            break;
        }
        if (isDraw()) {
            std::cout << "\nIt's a draw!\n";
            break;
        }
    }
}

