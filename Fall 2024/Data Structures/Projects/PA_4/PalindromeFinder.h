#include "DNASeq.h"

class PalindromeFinder {
public:
    void processSequence(const std::string& DNA); // Main method to analyze each DNA sequence

    

private:
    bool isValidDNA(const std::string& DNA) const; // Checks if the DNA sequence is valid
    void findSubPalindromes(const DNASeq& seq);    // Finds palindromic substrings in the DNA sequence
};