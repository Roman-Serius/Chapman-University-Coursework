//Soren Marius
//002456139
//Marius@chapman.edu
//CPSC-350-01
//PA4: Genetic Palindromes
#ifndef PALINDROMEFINDER_H
#define PALINDROMEFINDER_H

#include "DNASeq.h"
#include <iostream>

class PalindromeFinder {
public:
    void analyzeSequence(const std::string &sequence);
};

void PalindromeFinder::analyzeSequence(const std::string &sequence) {
    DNASeq dna(sequence);
    if (!dna.isGeneticPalindrome()) {
        std::cout << sequence << " - Not a Genetic Palindrome" << std::endl;
    } else {
        std::cout << sequence << " - Genetic Palindrome" << std::endl;
    }

    // Finding substrings
     int len = dna.sequence.size();
    for (int substrLen = 5; substrLen < len; substrLen++) { // Start with smallest valid length (5)
        for (int start = 0; start <= len - substrLen; start++) {
            int end = start + substrLen;
            DNASeq subSeq = dna.substring(start, end);
            if (subSeq.isGeneticPalindrome()) {
                // Print the substring if it's a genetic palindrome
                std::cout<<"     Substring ";
                for (int k = start; k < end; k++) {
                    std::cout << dna.sequence.get(k);
                }
                std::cout << " - Genetic Palindrome" << std::endl;
            }
        }
    }
}

#endif