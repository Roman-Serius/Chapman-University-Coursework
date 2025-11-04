/*
 * Soren Marius
 * 002456139
 * Marius@chapman.edu
 * CPSC-350-01
 * PA5: Scare Games
 */

#ifndef TOURNAMENTNODE_H
#define TOURNAMENTNODE_H

template <typename T>
class TournamentNode {
public:
    T* winner; // Pointer to the winner
    TournamentNode* left; // Pointer to the left child
    TournamentNode* right; // Pointer to the right child

    // Constructor to initialize the node with a winner
    TournamentNode(T* winner)
        : winner(winner), left(nullptr), right(nullptr) {}
};

#endif // TOURNAMENTNODE_H