//Soren Marius
//002456139
//Marius@chapman.edu
//CPSC-350-01
//PA1: Robber Language Translation

#include "Translator.h"
#include <cctype>

Translator::Translator(){
    cout << "Translator Created" << endl;

};

Translator::~Translator(){
    cout << "Translator Deconstructed" << endl;
}

//Translates english strings (with punctuation) to Robber Language
string Translator::translateEnglishSentence(string word){
    newWord = "";
    for (string::size_type i=0; i< word.size();++i){    
        char c = word[i];
        if (isalpha(c)){
            
            if (c== 'A'| c== 'a'| c== 'E'| c== 'e'| c== 'I'| c== 'i'| c== 'O'| c== 'o'| c== 'U'| c== 'u'){
                newCharacter = model.translateSingleVowel (c);
            }
            else{
                newCharacter = model.translateSingleConsonant (c);
            }
        }
        else {
            newCharacter = c;
        }
        newWord += newCharacter;
        
    };
    
    return newWord;
};


//Only works on english words
string Translator::translateEnglishWord(string word){
    for (string::size_type i=0; i< word.size();++i){    
        char c = word[i];
        
        if (c== 'A'| c== 'a'| c== 'E'| c== 'e'| c== 'I'| c== 'i'| c== 'O'| c== 'o'| c== 'U'| c== 'u'){
            newCharacter = model.translateSingleVowel (c);
        }
        else{
            newCharacter = model.translateSingleConsonant (c);
            }
        
        newCharacter = c;
        
        newWord += newCharacter;
        
    };
    
    return newWord;

}