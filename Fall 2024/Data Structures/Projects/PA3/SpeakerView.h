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