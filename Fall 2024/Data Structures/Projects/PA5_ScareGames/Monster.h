/*
 * Soren Marius
 * 002456139
 * Marius@chapman.edu
 * CPSC-350-01
 * PA5: Scare Games
 */

#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include <vector>

class Monster {
private:
    std::string name;      // Monster's name
    int screamPower;       // Monster's scream power

public:
    static void printMonsters(const std::vector<Monster*>& monsters); // Prints details of monsters
    Monster(const std::string& name, int screamPower);                // Constructor
    ~Monster();                                                       // Destructor

    std::string getName() const;      // Gets monster's name
    int getScreamPower() const;       // Gets monster's scream power

    bool operator>(const Monster& other) const; // Compares scream power
    bool operator<(const Monster& other) const; // Compares scream power
};

#endif // MONSTER_H