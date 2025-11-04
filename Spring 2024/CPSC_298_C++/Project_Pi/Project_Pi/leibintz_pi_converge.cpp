//
//  leibintz_pi_converge.cpp
//  Project_Pi
//
//  Created by Soren on 5/2/24.
//
#include<iostream>
#include <stdio.h>
#include <cmath>
#include <cfloat>
#include <iomanip>

int n =2;
float pi =0;
int leibnitz_pi_converge() {
    for(n=2;n<=pow(2,20);n*=2)
    {
        pi =0;
        for(int i=0; i<=n; i++)
        {
            pi += 4*(pow(-1,i))/((2*i)+1);
        }
        std::cout << "PI (approx): " << std::setprecision(DBL_DIG)<< pi << "; n: " << std::setw(7) <<  n << std::endl;
    }
    
    
    return 0;
}
int main(){
    leibnitz_pi_converge();
    return 0;
}
