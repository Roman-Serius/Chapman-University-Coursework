/*
 * Soren Marius
 * 002456139
 * Marius@chapman.edu
 * CPSC-350-01
 * PA5: Scare Games
 */

#include <iostream>
#include "RunScareGame.h"

int main(int argc, char* argv[]) {
    // Ensure correct number of arguments
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input file> <tournament format>\n";
        return 1;
    }

    RunScareGame game;
    game.runTournament(argv[1], argv[2]); // Execute the tournament based on input

    return 0;
}