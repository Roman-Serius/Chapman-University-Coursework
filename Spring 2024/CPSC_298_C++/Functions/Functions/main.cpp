//
//  main.cpp
//  Functions
//
//  Created by Soren on 3/14/24.
//

#include <iostream>

using namespace std;

float bodyTempC();
float bodyTempF();

int main(){
    std::cout << bodyTempC()<<endl;
    
    std::cout<< bodyTempF()<<endl;
    return 0;
}

float bodyTempC(){
    float temperature = 37;
    return temperature;
}

float bodyTempF(){
    float temperature = 98.6;
    return temperature;
}
