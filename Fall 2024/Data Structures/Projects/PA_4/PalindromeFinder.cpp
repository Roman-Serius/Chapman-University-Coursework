#include "PalindromeFinder.h"
#include <iostream>

// processSequence(DNA): Analyzes a DNA string
void PalindromeFinder::processSequence(const std::string& DNA) {
    if (!isValidDNA(DNA)) {
        std::cout << DNA << " - INVALID" << std::endl;
        return;
    }

    DNASeq seq(DNA);
    if (seq.isGeneticPalindrome()) {
        std::cout << DNA << " - Genetic Palindrome" << std::endl;
    } else {
        std::cout << DNA << " - Not a Genetic Palindrome" << std::endl;
    }

    findSubPalindromes(seq); // Find and display palindromic substrings
}

// isValidDNA(DNA): Validates if the string only contains A, C, T, and G
bool PalindromeFinder::isValidDNA(const std::string& DNA) const {
    for (char nucleotide : DNA) {
        if (nucleotide != 'A' && nucleotide != 'C' && nucleotide != 'T' && nucleotide != 'G') {
            return false;
        }
    }
    return true;
}

// findSubPalindromes(seq): Finds and prints palindromic substrings in DNASeq
void PalindromeFinder::findSubPalindromes(const DNASeq& seq) {
    int n = seq.size();

    for (int len = 5; len < n; ++len) { // Substrings of lengths from 5 to n-1
        for (int start = 0; start <= n - len; ++start) {
            DNASeq subSeq = seq.substring(start, start + len);
            if (subSeq.isGeneticPalindrome()) {
                std::cout << "Substring " << start << "-" << start + len << " - Genetic Palindrome" << std::endl;
            }
        }
    }
}