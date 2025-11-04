/*
 * Soren Marius
 * 002456139
 * Marius@chapman.edu
 * CPSC-350-01
 * PA5: Scare Games
 */

#ifndef TOURNAMENTTREE_H
#define TOURNAMENTTREE_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "TournamentNode.h"
#include "Monster.h"
template <typename T>
class TournamentTree {
private:
    TournamentNode<T>* root; // Root for the Winner's Bracket
    TournamentNode<T>* losersRoot; // Root for the Loser's Bracket
    


    TournamentNode<T>* buildTree(std::vector<T*>& competitors, int start, int end, std::vector<T*>& losers);
    void printTreeHelper(TournamentNode<T>* node);
    void deleteTree(TournamentNode<T>* node);

    // Add saveTreeAsDotHelper as a private member
    void saveTreeAsDotHelper(TournamentNode<T>* node, std::ofstream& file, int& nodeID);

public:
    TournamentTree() : root(nullptr), losersRoot(nullptr) {}
    ~TournamentTree() { deleteTree(root); root = nullptr; }

    void buildLosersBracket(std::vector<T*>& competitors);
    void buildSingleEliminationTree(std::vector<T*>& competitors, std::vector<T*>& losers);
    void printTournamentTree();
    void SaveTreeAsDot(const std::string& filename, TournamentNode<T>* rootNode);
    void setRoot(TournamentNode<T>* newRoot);

    TournamentNode<T>* getRoot() const { return root; }
};

#include "TournamentTree.tpp" // Include template definitions
#endif // TOURNAMENTTREE_H