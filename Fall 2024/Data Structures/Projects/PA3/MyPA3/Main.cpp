//Soren Marius
//002456139
//Marius@chapman.edu
//CPSC-350-01
//PA3: Do You See What I See?
#include <iostream>
#include "SpeakerView.h"


int main(int argc, char* argv[]) {
    

    const char* filename = argv[1];
    SpeakerView speakerView(filename);
    speakerView.calculateSpeakerView();

    return 0;
}