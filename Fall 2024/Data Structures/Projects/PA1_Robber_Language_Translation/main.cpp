//Soren Marius
//002456139
//Marius@chapman.edu
//CPSC-350-01
//PA1: Robber Language Translation

#include "Translator.h"
#include "FileProcessor.h"

int main(int argc, char** argv){
    

   FileProcessor file;
   file.processFile(argv[1],argv[2]);

    return 0;
}