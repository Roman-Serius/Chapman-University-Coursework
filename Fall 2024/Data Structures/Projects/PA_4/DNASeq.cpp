#include "DNASeq.h"

// Default constructor - Initialize an empty DNA sequence
DNASeq::DNASeq() {
    // sequence is initialized empty using DblList
}

// Overloaded constructor - Initialize DNA sequence from a string
DNASeq::DNASeq(const std::string& DNA) {
    for (char nucleotide : DNA) {
        sequence.addFront(nucleotide); // Insert each nucleotide into the sequence
    }
}

// Destructor
DNASeq::~DNASeq() {
    // Destructor code here (DblList destructor will handle cleanup)
}

// complement(): Returns a new DNASeq with the complement of the current sequence
DNASeq DNASeq::complement() const {
    DNASeq compSeq;
    for (int i = 0; i < sequence.getSize(); ++i) {
        char nucleotide = sequence.get(i);
        char complement;
        
        // Determine complement character based on nucleotide
        switch (nucleotide) {
            case 'A': complement = 'T'; break;
            case 'T': complement = 'A'; break;
            case 'C': complement = 'G'; break;
            case 'G': complement = 'C'; break;
            default:  complement = nucleotide; // Handle unexpected characters if needed
        }
        
        compSeq.sequence.addFront(complement);
    }
    return compSeq;
}

// substring(s, e): Returns a DNASeq that is a substring from s to e
DNASeq DNASeq::substring(int s, int e) const {
    DNASeq subSeq;
    for (int i = s; i < e && i < sequence.getSize(); ++i) {
        subSeq.sequence.addFront(sequence.get(i)); // Add each character in the range
    }
    return subSeq;
}

int DNASeq::size() const {
    return sequence.getSize(); // Use DblList's getSize() to return the size
}

// isGeneticPalindrome(): Checks if the DNA sequence is a genetic palindrome
bool DNASeq::isGeneticPalindrome() const {
    DNASeq compSeq = this->complement();
    int n = sequence.getSize();

    // Compare the sequence with the reverse of its complement
    for (int i = 0; i < n; ++i) {
        if (sequence.get(i) != compSeq.sequence.get(n - i - 1)) {
            return false; // If mismatch, not a palindrome
        }
    }
    return true; // All characters match in reverse
}