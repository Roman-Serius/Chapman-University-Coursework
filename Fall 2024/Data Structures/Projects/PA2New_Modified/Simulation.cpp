#include "Simulation.h"

//constructor
Simulation::Simulation(int L, int gridSize, int V, const std::string& logFileName) 
: world(L,gridSize), mario(V, 0, 0, 0)
    {
        logFile.open(logFileName);
        //random number generation
        //stack overflow used for unsigned int: https://stackoverflow.com/questions/1282295/what-is-the-nullptr-keyword-and-why-is-it-better-than-null
        srand(static_cast<unsigned int>(time(0))); 
    }

    //deconstructor
    Simulation::~Simulation() 
    {
        logFile.close();
    }

    //run simulation
    void Simulation::simulate()
    {
        int currentLevel = 0;
        int marioRow = rand() % world.gridSize;
        int marioCol = rand() % world.gridSize;

        while (mario.lives > 0 && currentLevel < world.L) 
        {
            logCurrentState(currentLevel, marioRow, marioCol);
            char item = world.levels[currentLevel].grid[marioRow][marioCol];
            interact(item, currentLevel, marioRow, marioCol);

            if(item == 'w')
            {
                currentLevel++;
                marioRow = rand() % world.gridSize;
                marioCol = rand() % world.gridSize;
                continue;
            }

            moveMario(marioRow, marioCol);

        }

        logResult(currentLevel == world.L);

    }

    //item interactions
    void Simulation::interact(char item, int &level, int &row, int &col)
    {
        switch (item)
        {
            case 'c':
                mario.coinCollect();
                logFile << "Mario collected a coin\n";
                break;
            case 'm':
                mario.powerIncrease();
                logFile << "Mario ate a mushroom\n";
                break;
            case 'g':
                fightGoomba();
                break;
            case 'k':
                fightKoopa();
                break;
            case 'b':
                fightBoss(level, row, col);
                break;
            case 'x':
                logFile << "Position is empty\n";
                break;
            case 'w':
                logFile << "Mario warped to next level\n";
                break;
        }
        //empty after interaction
        world.levels[level].placeItem(row, col, 'x');
    }

void Simulation::fightGoomba()
{
    if(rand() % 100 < 80)
    {
        mario.defeatedEnemy();
        logFile << "Mario fought a Goomba and won\n";
    }
    else
    {
        if (mario.PowerLevel > 0)
        {
            mario.PowerLevel--;
        }
        else
        {
            mario.loseLife();
        }
        logFile << "Mario fought a Goomba and lost\n";
    }
}

//koopa fighting
void Simulation::fightKoopa()
{
    if(rand() % 100 < 65)
    {
        mario.defeatedEnemy();
        logFile << "Mario fought a Koopa and won\n";
    }
     else
    {
        if (mario.PowerLevel > 0)
        {
            mario.PowerLevel--;
        }
        else
        {
            mario.loseLife();
        }
        logFile << "Mario fought a Koopa and lost\n";
    }
}

//boss fight

void Simulation::fightBoss(int &level, int &row, int&col) 
{
    if(rand() % 100 < 50)
    {
        logFile << "Mario fought the boss and won\n";
        level++;
        row = col = 0;
    }
    else
    {
        mario.PowerLevel = std::max(0, mario.PowerLevel - 2);
        if (mario.PowerLevel == 0)
        {
            mario.loseLife();
        }
        logFile << "Mario fought the boss and lost\n";
    }
}

//mario movement

void Simulation::moveMario(int &row, int &col)
{
    int direction = rand() % 4;
    switch (direction)
    {
        case 0:
            row = (row-1+world.gridSize) % world.gridSize;
            logFile << "Mario moved up\n";
            break;
        case 1:
            row = (row + 1) % world.gridSize;
            logFile << "Mario moved down\n";
        case 2: 
            col = (col-1+world.gridSize) % world.gridSize;
            logFile << "Mario moved left\n";
            break;
        case 3:
            col = (col+1) % world.gridSize;
            logFile << "Mario moved right\n";
            break;
    }
}

//log current game state

void Simulation::logCurrentState(int level, int row, int col)
{
    logFile << "Level " << level + 1 << ", Position: (" << row << "," << col << "). Power Level: " << mario.PowerLevel << ", Lives: " << mario.lives << ", Coins: " << mario.coins << std::endl;
}

//log game results

void Simulation::logResult(bool gameWon)
{
    if (gameWon)
    {
        logFile << "Mario won the game!\n";
    }
    else
    {
        logFile << "Mario lost the game.\n";
    }
}

