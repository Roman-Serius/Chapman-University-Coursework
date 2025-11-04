/*
 * Soren Marius
 * 002456139
 * Marius@chapman.edu
 * CPSC-350-01
 * PA5: Scare Games
 */

#include "Monster.h"
#include <iostream>

// Constructor to initialize Monster with name and scream power
Monster::Monster(const std::string& name, int screamPower)
    : name(name), screamPower(screamPower) 
{
    std::cout << "Monster created: " << name << "\n";
}

// Destructor to clean up Monster
Monster::~Monster() {
    std::cout << "Monster destroyed: " << name << "\n";
}

// Returns the name of the Monster
std::string Monster::getName() const {
    return name;
}

// Returns the scream power of the Monster
int Monster::getScreamPower() const {
    return screamPower;
}

// Prints details of a vector of Monster pointers
void Monster::printMonsters(const std::vector<Monster*>& monsters) {
    for (const Monster* monster : monsters) {
        if (monster) {
            std::cout << "Monster: " << monster->getName()
                      << " | Scream Power: " << monster->getScreamPower()
                      << "\n";
        } else {
            std::cout << "Invalid Monster (nullptr)\n";
        }
    }
}

// Compare operator: checks if this Monster's scream power is greater
bool Monster::operator>(const Monster& other) const {
    return screamPower > other.screamPower;
}

// Compare operator: checks if this Monster's scream power is less
bool Monster::operator<(const Monster& other) const {
    return screamPower < other.screamPower;
}