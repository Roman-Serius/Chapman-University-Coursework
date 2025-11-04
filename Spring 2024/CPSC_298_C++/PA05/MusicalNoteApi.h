//
/// @brief Musical Notes Application Programming Interface (API) Header File
/// CPSC-298-6 Programming in C++ Project Musical Note Frequencies with Functions
/// @author marius@chapman.edu

#ifndef MUSICAL_NOTE_API_H
#define MUSICAL_NOTE_API_H
#include <iostream>


// Constants
const int kNumOctaves = 11;
const int kHalfTonesInOctave = 12;
const int kNoteNamesCount = 12;
const double kStandardA4FrequencyHz = 440.0;
const int kStandardA4Octave = 4;
const int kStandardA4HalfTone = 9;
const double kSpeedOfSoundCmPerSec = 34300.0;

/// @brief Compute the frequency of a musical note.
/// @param octave The octave number (0 to 10)
/// @param halfToneIndex The index within the octave (0 to 11)
/// @return Frequency in Hertz if valid, otherwise -1
/// @pre octave is between 0 and kNumOctaves
/// @pre halfToneIndex is between 0 and kHalfTonesInOctave
double computeFrequency(int octave, int halfToneIndex);

/// @brief Compute the wavelength of a musical note in centimeters.
/// @param frequency The frequency in Hertz
/// @return Wavelength in centimeters if valid, otherwise -1
/// @pre frequency > 0
double computeWavelengthInCm(double frequency);

/// @brief Get the name of the note given the octave and half-tone index.
/// @param octave The octave number (0 to 10)
/// @param halfToneIndex The index within the octave (0 to 11)
/// @return Name of the note as a string, or "UNK" if invalid
/// @pre octave is between 0 and kNumOctaves
/// @pre halfToneIndex is between 0 and kHalfTonesInOctave
std::string getNoteName(int octave, int halfToneIndex);

#endif // MUSICAL_NOTE_API_H
