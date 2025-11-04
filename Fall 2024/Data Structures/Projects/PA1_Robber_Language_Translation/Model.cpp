//Soren Marius
//002456139
//Marius@chapman.edu
//CPSC-350-01
//PA1: Robber Language Translation

#include "Model.h"
#include <cstdlib>

Model::Model(){
    cout<< "Model Created" << endl;
}
Model::~Model(){
    cout<< "Model Deconstructed" << endl;
}

//doubles consonants with a o in the middle
string Model::translateSingleConsonant(char consonant){
    return string(1, consonant) + "o" + string(1, consonant);
}

//returns same vowel
string Model::translateSingleVowel(char vowel){
    return string(1, vowel);
}

