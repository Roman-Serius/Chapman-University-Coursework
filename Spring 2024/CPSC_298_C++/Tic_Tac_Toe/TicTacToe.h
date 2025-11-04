//
//  TicTacToe.h
//  Tic_Tac_Toe
//
//  Created by Soren on 5/9/24.
//

#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe {
private:
    char** grid; // Pointer to a 2D array (game grid)
    int rows, cols; // Size of the grid (3x3)

    void initializeGrid(); // Initialize the grid with '~'
    bool isWin(char player); // Check if a player has won
    bool isDraw(); // Check if the game is a draw
    void displayGrid(); // Print the current grid state
    void getPlayerMove(); // Get and validate player's move
    void getComputerMove(); // Basic AI for computer move

public:
    TicTacToe(); // Constructor to set up the game
    ~TicTacToe(); // Destructor to clean up memory
    void play(); // Main function to handle the game loop
};

#endif // TICTACTOE_H
