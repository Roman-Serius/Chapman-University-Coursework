/*
 * Soren Marius
 * 002456139
 * Marius@chapman.edu
 * CPSC-350-01
 * PA5: Scare Games
 */

#include "RunScareGame.h"
#include "TournamentTree.h"
#include "Monster.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

void RunScareGame::runTournament(const std::string& inputFile, const std::string& format) {
    // Read competitors from the input file
    std::vector<Monster*> competitors;
    std::ifstream file(inputFile);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open input file " << inputFile << "\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name;
        int screamPower;

        ss >> name >> screamPower; // Parse name and scream power
        if (ss.fail()) {
            std::cerr << "Error: Malformed line in input file: " << line << "\n";
            continue;
        }

        competitors.push_back(new Monster(name, screamPower));
    }
    file.close();

    if (competitors.empty()) {
        std::cerr << "Error: No valid competitors found in input file.\n";
        return;
    }

    Monster::printMonsters(competitors);

    TournamentTree<Monster> tree;

    if (format == "single") {
        std::vector<Monster*> empty;
        std::cout << "Running a single-elimination tournament...\n";
        tree.buildSingleEliminationTree(competitors, empty);
        std::cout << "Winner's Bracket Results:\n";
        tree.printTournamentTree();
        tree.SaveTreeAsDot("winners_bracket.dot", tree.getRoot());
    } 
    else if (format == "double") {
        std::cout << "Running a double-elimination tournament...\n";

        // Winner's Bracket
        std::vector<Monster*> losers;
        tree.buildSingleEliminationTree(competitors, losers);
        std::cout << "Winner's Bracket Results:\n";
        tree.printTournamentTree();
        tree.SaveTreeAsDot("winners_bracket.dot", tree.getRoot());

        TournamentNode<Monster>* winnersBracketChampion = tree.getRoot();

        // Loser's Bracket
        TournamentTree<Monster> losersTree;
        losersTree.buildLosersBracket(losers);
        std::cout << "Loser's Bracket Results:\n";
        losersTree.printTournamentTree();
        losersTree.SaveTreeAsDot("losers_bracket.dot", losersTree.getRoot());

        TournamentNode<Monster>* losersBracketChampion = losersTree.getRoot();

        // Final Match
        TournamentTree<Monster> unifiedTree;
        Monster* finalWinnerMonster = (winnersBracketChampion->winner->getScreamPower() >
                                       losersBracketChampion->winner->getScreamPower())
                                      ? winnersBracketChampion->winner
                                      : losersBracketChampion->winner;

        TournamentNode<Monster>* finalMatchNode = new TournamentNode<Monster>(finalWinnerMonster);
        finalMatchNode->left = winnersBracketChampion;
        finalMatchNode->right = losersBracketChampion;

        unifiedTree.setRoot(finalMatchNode);

        std::cout << "Unified Tournament Tree with Final Match:\n";
        unifiedTree.printTournamentTree();
        unifiedTree.SaveTreeAsDot("final_tournament_tree.dot", unifiedTree.getRoot());
        std::cout << "Final tournament tree saved to 'final_tournament_tree.dot'.\n";
    } 
    else {
        std::cerr << "Error: Unsupported tournament format '" << format << "'.\n";
        return;
    }

    // Cleanup
    for (Monster*& monster : competitors) {
        if (monster != nullptr) {
            std::cout << "Deleting Monster: " << monster->getName() << "\n";
            delete monster;
            monster = nullptr;
        }
    }
}