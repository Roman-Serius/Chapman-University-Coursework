#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "World.h"
#include "Mario.h"

class Simulation 
{
    public:
     Simulation(int L, int gridSize, int V, const std::string& logFileName);
     ~Simulation();

     void simulate();




     private: 
        //world object with levels
        World world;
        //mario object representing the player
        Mario mario;
        //log file to record game
        std::ofstream logFile;

        void interact(char item, int& level, int& row, int& col);
        void fightGoomba();
        void fightKoopa();
        void fightBoss(int& level, int& row, int& col);
        void moveMario(int& row, int& col);
        void logCurrentState(int level, int row, int col);
        void logResult(bool gameWon);

};
#endif