//
//  MusicalNoteImpl.cpp
//  PA05
//
//  Created by Soren on 5/10/24.
// @author marius@chapman.edu
#include "MusicalNoteApi.h"
#include <iostream>
#include <cmath>
#include <string>
#include <vector>



// Note names for each half-tone
const std::vector<std::string> noteNames = {
    "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"
};

double computeFrequency(int octave, int halfToneIndex) {
    // Preconditions
    if (octave < 0 || octave >= kNumOctaves || halfToneIndex < 0 || halfToneIndex >= kHalfTonesInOctave) {
        return -1;
    }

    // Calculate the number of half-tones from standard A4
    int halfTonesFromA4 = (octave - kStandardA4Octave) * kHalfTonesInOctave + (halfToneIndex - kStandardA4HalfTone);

    // Calculate the frequency using the formula: f = A4 * 2^(n/12)
    return kStandardA4FrequencyHz * std::pow(2.0, halfTonesFromA4 / 12.0);
}

double computeWavelengthInCm(double frequency) {
    // Preconditions
    if (frequency <= 0) {
        return -1;
    }

    // Calculate wavelength: λ = v / f
    return kSpeedOfSoundCmPerSec / frequency;
}

std::string getNoteName(int octave, int halfToneIndex) {
    // Preconditions
    if (octave < 0 || octave >= kNumOctaves || halfToneIndex < 0 || halfToneIndex >= kHalfTonesInOctave) {
        return "UNK";
    }

    // Concatenate the note name with the octave number
    return noteNames[halfToneIndex] + std::to_string(octave);
}

int main() {
    // Generate frequencies and wavelengths for all notes in all octaves
    for (int octave = 0; octave < kNumOctaves; ++octave) {
        for (int halfToneIndex = 0; halfToneIndex < kHalfTonesInOctave; ++halfToneIndex) {
            double frequency = computeFrequency(octave, halfToneIndex);
            double wavelength = computeWavelengthInCm(frequency);
            std::string noteName = getNoteName(octave, halfToneIndex);
            std::cout << noteName << ": " << frequency << " Hz, " << wavelength << " cm\n";
        }
    }

    // Test error handling with incorrect inputs
    std::cout << "Testing error handling:\n";
    std::cout << "Invalid frequency: " << computeFrequency(-1, 0) << " Hz\n";
    std::cout << "Invalid wavelength: " << computeWavelengthInCm(-100) << " cm\n";
    std::cout << "Invalid note name: " << getNoteName(12, 0) << "\n";

    return 0;
}
