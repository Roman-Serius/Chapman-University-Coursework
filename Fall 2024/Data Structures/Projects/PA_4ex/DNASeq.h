//Soren Marius
//002456139
//Marius@chapman.edu
//CPSC-350-01
//PA4: Genetic Palindromes
#ifndef DNASEQ_H
#define DNASEQ_H

#include "DblList.h"
#include <iostream>

class DNASeq {
public:
    DblList<char> sequence;

    DNASeq() {}
    DNASeq(const std::string &seq);

    DNASeq complement();
    DNASeq substring(int start, int end);
    bool isGeneticPalindrome();

private:
    char complementBase(char base);
};

DNASeq::DNASeq(const std::string &seq) {
    for (char c : seq) {
        sequence.append(c);
    }
}

char DNASeq::complementBase(char base) {
    switch (base) {
        case 'A': return 'T';
        case 'T': return 'A';
        case 'C': return 'G';
        case 'G': return 'C';
        default: return '\0';
    }
}

DNASeq DNASeq::complement() {
    DNASeq compSeq;
    for (int i = 0; i < sequence.size(); i++) {
        compSeq.sequence.append(complementBase(sequence.get(i)));
    }
    return compSeq;
}

DNASeq DNASeq::substring(int start, int end) {
    DNASeq subSeq;
    for (int i = start; i < end; i++) {
        subSeq.sequence.append(sequence.get(i));
    }
    return subSeq;
}

bool DNASeq::isGeneticPalindrome() {
    DNASeq compSeq = this->complement();
    int len = sequence.size();
    for (int i = 0; i < len; i++) {
        if (sequence.get(i) != compSeq.sequence.get(len - i - 1)) {
            return false;
        }
    }
    return true;
}

#endif