//
//  main.cpp
//  PAO3
//
//  Created by Soren on 2/22/24.
//

#include <iostream>
#include <string>

int main() {
    // Part I: Prompt and Display Codes
    std::string hardCodedCode = "ECA";
    std::string userCode;

    std::cout << "Enter the three letter message code: ";
    std::cin >> userCode;

    std::cout << "Authenticator Code: " << hardCodedCode << std::endl;
    std::cout << "Message Code: " << userCode << std::endl;

    // Part II: Character-by-Character Comparison
    std::cout << "Character by character comparison: " << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << "Character " << i + 1 << ": ";
        if (hardCodedCode[i] == userCode[i]) {
            std::cout << "Match" << std::endl;
        } else {
            std::cout << "Does not match" << std::endl;
        }
    }

    // Part III: String Comparison
    if (hardCodedCode == userCode) {
        std::cout << "Concurrence: message is authentic" << std::endl;
    } else {
        std::cout << "Concurrence: message is invalid" << std::endl;
    }

    // Part IV: Characterizing the Code
    std::cout << "Characterizing the code..." << std::endl;
    int checksum = 0;
    for (char c : userCode) {
        checksum+= int(c);
    }
    checksum = checksum%7;
    
    const int k_iValidCodeChecksum = 5;
    
    if (checksum == k_iValidCodeChecksum){
        std::cout << "Message Code is valid: 5"  << std::endl;
    } else{
        std::cout << "Message Codes is invalid:" << checksum << "Expected:" << k_iValidCodeChecksum << std::endl;
    }
    checksum=0;
    for (char c : userCode){
        std::cout << "ASCII values of message code:" << int(c) << std::endl;
        checksum += int(c);
    }
    std::cout << "Sum of ASCII values:" << checksum << std::endl;
    
    for (char k : hardCodedCode){
        for (char c : userCode){
            if (k=='E'){
                if (k != c){
                    std::cout << "First characters do not match: Message: " << c << "; Authenticator: E";
                }
            }else if (k=='C'){
                if (k != c){
                    std::cout << "Second characters do not match: Message: " << c << "; Authenticator: C";
                }
            }else if (k=='A'){
                if (k != c){
                    std::cout << "Third characters do not match: Message: " << c << "; Authenticator: A";
                }
            }
        }
    }
    if (checksum < int('E')+int('C')+int('A')){
        std::cout << "Message code: " << userCode << "is lexicographically less than Authenticator code: ECA"<< std::endl;
    }
    else if (checksum > int('E')+int('C')+int('A')){
        std::cout << "Message code: " << userCode << "is lexicographically less than Authenticator code: ECA"<< std::endl;
    }
    return 0;
}

