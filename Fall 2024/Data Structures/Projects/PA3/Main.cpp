#include <iostream>
#include "SpeakerView.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input file>" << std::endl;
        return 1;
    }

    const char* filename = argv[1];
    SpeakerView speakerView(filename);
    speakerView.calculateSpeakerView();

    return 0;
}