//Soren Marius
//002456139
//Marius@chapman.edu
//CPSC-350-01
//PA1: Robber Language Translation

#ifndef MODEL_H
#define MODEL_H

#include <iostream>
using namespace std;

class Model{

    public:
        Model();
        ~Model();
        string translateSingleConsonant(char consonant);
        string translateSingleVowel(char vowel);



};

#endif
