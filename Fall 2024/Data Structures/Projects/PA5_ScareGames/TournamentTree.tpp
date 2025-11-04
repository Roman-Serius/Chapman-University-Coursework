/*
 * Soren Marius
 * 002456139
 * Marius@chapman.edu
 * CPSC-350-01
 * PA5: Scare Games
 */

#include "TournamentTree.h"

// Builds the tournament tree recursively
template <typename T>
TournamentNode<T>* TournamentTree<T>::buildTree(std::vector<T*>& competitors, int start, int end, std::vector<T*>& losers) {
    if (start > end) return nullptr;

    if (start == end) return new TournamentNode<T>(competitors[start]);

    int mid = (start + end) / 2;
    TournamentNode<T>* leftChild = buildTree(competitors, start, mid, losers);
    TournamentNode<T>* rightChild = buildTree(competitors, mid + 1, end, losers);

    T* winner = (leftChild->winner->getScreamPower() > rightChild->winner->getScreamPower())
                    ? leftChild->winner
                    : rightChild->winner;

    // Add the loser to the losers vector
    T* loser = (leftChild->winner == winner) ? rightChild->winner : leftChild->winner;
    losers.push_back(loser);

    TournamentNode<T>* parentNode = new TournamentNode<T>(winner);
    parentNode->left = leftChild;
    parentNode->right = rightChild;

    return parentNode;
}

// Deletes the tournament tree and its nodes
template <typename T>
void TournamentTree<T>::deleteTree(TournamentNode<T>* node) {
    if (!node) return;

    std::cout << "Deleting node: " << (node->winner ? node->winner->getName() : "null") << "\n";

    deleteTree(node->left);
    deleteTree(node->right);

    if (node->winner) {
        delete node->winner;
        node->winner = nullptr;
    }

    delete node;
}

// Sets a new root for the tree, deleting the previous one
template <typename T>
void TournamentTree<T>::setRoot(TournamentNode<T>* newRoot) {
    if (root == newRoot) return;
    if (root) {
        deleteTree(root);
        root = nullptr;
    }
    root = newRoot;
}

// Prints the tournament tree
template <typename T>
void TournamentTree<T>::printTreeHelper(TournamentNode<T>* node) {
    if (!node) return;

    if (node->left && node->right) {
        std::cout << "Match: " << node->left->winner->getName() << " vs "
                  << node->right->winner->getName() << " -> Winner: "
                  << node->winner->getName() << "\n";
    } else if (node->winner) {
        std::cout << "Competitor: " << node->winner->getName() << " (Power: "
                  << node->winner->getScreamPower() << ")\n";
    }

    printTreeHelper(node->left);
    printTreeHelper(node->right);
}

// Builds a single-elimination tournament tree
template <typename T>
void TournamentTree<T>::buildSingleEliminationTree(std::vector<T*>& competitors, std::vector<T*>& losers) {
    root = buildTree(competitors, 0, competitors.size() - 1, losers);
}

// Builds the loser's bracket tree
template <typename T>
void TournamentTree<T>::buildLosersBracket(std::vector<T*>& losers) {
    if (losers.empty()) {
        std::cerr << "Error: No competitors for Loser's Bracket.\n";
        return;
    }
    std::vector<Monster*> empty;
    root = buildTree(losers, 0, losers.size() - 1, empty);
}

// Prints the entire tournament tree
template <typename T>
void TournamentTree<T>::printTournamentTree() {
    printTreeHelper(root);
}

// Saves the tree structure as a DOT file
template <typename T>
void TournamentTree<T>::saveTreeAsDotHelper(TournamentNode<T>* node, std::ofstream& file, int& nodeID) {
    if (node == nullptr) return;

    int currentID = nodeID++;
    file << "    node" << currentID << " [label=\"" << node->winner->getName()
         << " (Power: " << node->winner->getScreamPower() << ")\"];\n";

    if (node->left) {
        int leftID = nodeID;
        saveTreeAsDotHelper(node->left, file, nodeID);
        file << "    node" << currentID << " -> node" << leftID << ";\n";
    }

    if (node->right) {
        int rightID = nodeID;
        saveTreeAsDotHelper(node->right, file, nodeID);
        file << "    node" << currentID << " -> node" << rightID << ";\n";
    }
}

// Wrapper for saving the tree as a DOT file
template <typename T>
void TournamentTree<T>::SaveTreeAsDot(const std::string& filename, TournamentNode<T>* rootNode) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file for DOT output: " << filename << "\n";
        return;
    }

    file << "digraph TournamentTree {\n";
    int nodeID = 0;
    saveTreeAsDotHelper(rootNode, file, nodeID);
    file << "}\n";
    file.close();
}