//Soren Marius
//002456139
//Marius@chapman.edu
//CPSC-350-01
//PA1: Robber Language Translation

#include "FileProcessor.h"
#include <cstdlib>
#include <fstream>
Translator T;
FileProcessor::FileProcessor(){
    cout << "FileProcessor Constructed" << endl;
};

FileProcessor::~FileProcessor(){
    cout<< "FileProcessor Deconstructed" << endl;
}

//opens input file, writes to output file, and translates to robber language
void FileProcessor::processFile(string input, string output){
    ofstream writeFile(output);
    ifstream readFile(input);
    while (getline(readFile,text)){
        writeFile << bolden(text) << endl;
        
    };
    readFile.close();
    writeFile << endl;
    ifstream readFile2(input);
    while (getline(readFile2,text)){
        writeFile <<italicize(T.translateEnglishSentence(text)) << endl;
    };
    

    readFile2.close();
    writeFile.close();
    
    
    

}

//boldens in hmtl

string FileProcessor::bolden(string regText){
    return "<p><b>" + regText + "</b></p>";
}

//italicizes in html

string FileProcessor::italicize(string regText){
    return "<p><i>" + regText + "</i></p>";
}