//
//  main.cpp
//  PAO2
//
//  Created by Soren on 2/15/24.
//

#include <iostream>
#include <cmath>

using namespace std;

// Function to calculate the frequency of a note
double calculateFrequency(int octave, int halfStepsFromC0) {
    double f_R = 16.35; // Reference frequency for C0
    return f_R * pow(2, octave + halfStepsFromC0 / 12.0);
}
double calculatedWavelength(int octave, int halfStepsFromC0) {
    double freq = calculateFrequency(octave, halfStepsFromC0);
    return 345/freq ;
}

int main() {
    // Calculate and print the frequencies for the specified notes
    cout << "Reference Frequency: 16.35 Hz"<< endl;
    cout << "Speed of Sound: 345 m/s"<< endl;
    cout << "Note: C0; " << "Nu: 0; k: 0; frequency: "<< calculateFrequency(0, 0) << " Hz; wavelength: " << calculatedWavelength(0,0) << " cm" << endl;
    cout << "Note: C#0; " << "Nu: 0; k: 1; frequency: "<< calculateFrequency(0, 1) << " Hz; wavelength: " << calculatedWavelength(0, 1) << " cm" << endl;
    cout << "Note: D0; " << "Nu: 0; k: 2; frequency: "<< calculateFrequency(0, 2) << " Hz; wavelength: " << calculatedWavelength(0, 2) << " cm" << endl;
    cout << "Note: D3; " << "Nu: 3; k: 2; frequency: "<< calculateFrequency(3, 2) << " Hz; wavelength: " << calculatedWavelength(3, 2) << " cm" << endl;
    cout << "Note: C4; " << "Nu: 4; k: 0; frequency: "<< calculateFrequency(4, 0) << " Hz; wavelength: " << calculatedWavelength(4, 0) << " cm" << endl;
    cout << "Note: D#7; " << "Nu: 7; k: 3; frequency: "<< calculateFrequency(7, 3) << " Hz; wavelength: " << calculatedWavelength(7, 3) << " cm" << endl;
    cout << "Note: C8; " << "Nu: 8; k: 0; frequency: "<< calculateFrequency(8, 0) << " Hz; wavelength: " << calculatedWavelength(8, 0) << " cm" << endl;

    return 0;
}
