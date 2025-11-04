// Soren Marius
// 002456139
// Marius@chapman.edu
// CPSC-350-01
// PA2: Not so Super Mario Bros.
#include <iostream>
#include "Level.h"
#include "World.h"
#include "Simulation.h"
#include "FileProcessor.h"

using namespace std;

int main(int argc, char** argv)
{
    if(argc < 2) 
    {
        cerr << "Error: No input file Provided." << endl;
        return 1;
    }

    FileProcessor fileProcessor;
    Mario mario;


    fileProcessor.processFile(argv[1]);
   
   int numLevels = fileProcessor.getNumLevels();
    int gridSize = fileProcessor.getGridSize();
    int initialLives = fileProcessor.getInitLives();
    int perCoins = fileProcessor.getPerCoins();
    int perGoomba = fileProcessor.getPerGoomba();
    int perKoopa = fileProcessor.getPerKoopa();
    int perMushroom = fileProcessor.getPerMushroom();
    int perNothing = fileProcessor.getPerNothing();
   
   cout << numLevels << gridSize << initialLives << perCoins << perGoomba << perKoopa << perMushroom << perNothing << endl;

    

   Simulation simulation(numLevels, gridSize, initialLives, "GAME.txt",perCoins, perNothing, perGoomba, perKoopa, perMushroom);
   simulation.simulate(fileProcessor);
//    World world(numLevels,gridSize);

   
    

  

   
   
//    world.displayWorld(fileProcessor);  
//    fileProcessor.writeToFile("Mario is starting in position: ");

//    while (mario.getLives() != 0 ){
//     //Call for mario to move
//     //level.display(fileProcessor);
//     //display level and position
//     fileProcessor.writeToFile("Mario is at power level " + to_string(mario.getPowerLevel()) + "1");
//     //describe space
//     fileProcessor.writeToFile("Mario has" + to_string(mario.getLives()) + "lives left. Mario has" + to_string(mario.getCoins()) + "coins.");
//     //describe future space
//    };
 

    return 0;
}