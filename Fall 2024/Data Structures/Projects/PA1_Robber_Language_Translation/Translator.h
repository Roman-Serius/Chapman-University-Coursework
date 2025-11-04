//Soren Marius
//002456139
//Marius@chapman.edu
//CPSC-350-01
//PA1: Robber Language Translation

#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include "Model.h"
#include <iostream>
using namespace std;

class Translator{

    public:
        Translator();
        ~Translator();
        string translateEnglishWord(string englishWord);
        string translateEnglishSentence(string englishSentence);

    private:
        string newWord;
        string newCharacter;
        Model model;
};



#endif