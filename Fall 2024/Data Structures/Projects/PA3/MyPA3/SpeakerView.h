//Soren Marius
//002456139
//Marius@chapman.edu
//CPSC-350-01
//PA3: Do You See What I See?
#ifndef SPEAKERVIEW_H
#define SPEAKERVIEW_H

class SpeakerView {
private:
    double** heights;
    int rows;
    int cols;

public:
    SpeakerView(const char* filename);
    ~SpeakerView();
    void readFromFile(const char* filename);
    void calculateSpeakerView();
};

#endif