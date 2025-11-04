#include "DblList.h"

class DNASeq {
public:
    DNASeq();                               // Default constructor
    DNASeq(const std::string& DNA);         // Constructor that takes a DNA string
    ~DNASeq();                              // Destructor

    DNASeq complement() const;              // Returns the complement of the DNA sequence
    DNASeq substring(int s, int e) const;   // Returns a substring from index s to e
    bool isGeneticPalindrome() const; 
    
    int size() const;      

private:
    DblList<char> sequence;                 // Use DblList to store the DNA sequence
};