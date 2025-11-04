/*
 * Soren Marius
 * 002456139
 * Marius@chapman.edu
 * CPSC-350-01
 * PA5: Scare Games
 */

#ifndef RUNSCAREGAME_H
#define RUNSCAREGAME_H

#include <string>
#include <vector>
#include "TournamentTree.h"
#include "Monster.h"

class RunScareGame {
public:
    // Runs the tournament based on the input file and format (single or double elimination)
    void runTournament(const std::string& inputFile, const std::string& format);
};

#endif // RUNSCAREGAME_H