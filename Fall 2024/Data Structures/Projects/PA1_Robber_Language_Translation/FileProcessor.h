//Soren Marius
//002456139
//Marius@chapman.edu
//CPSC-350-01
//PA1: Robber Language Translation

#include <iostream>
#include "Translator.h"
using namespace std;

class FileProcessor{
    public:
        FileProcessor();
        ~FileProcessor();
        void processFile(string input,string output);

    private:

        string text;
        string bolden(string regText);
        string italicize(string regText);
        
};