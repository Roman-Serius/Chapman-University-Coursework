//
//  main.cpp
//  Tic_Tac_Toe
//
//  Created by Soren on 5/9/24.
//

#include <iostream>
#include "TicTacToe.h"

int main() {
    // Dynamically allocate the TicTacToe game object
    TicTacToe* game = new TicTacToe();

    // Start the game
    game->play();

    // Clean up
    delete game;

    return 0;
}
