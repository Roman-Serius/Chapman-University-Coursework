//
//  main.cpp
//  Marius_Sum_Exceptions
//
//  Created by Soren on 5/19/24.
//
// Marius@chapman.edu

#include <iostream>
#include <stdexcept>
#include <string>

unsigned long sigma(unsigned long n) {
    try {
        if (n < 1) {
            throw std::runtime_error("Precondition failed: n must be >= 1. " +
                std::string("Error in file: ") + __FILE__ + " on line: " + std::to_string(__LINE__) +
                ". Received n = " + std::to_string(n));
        }

        unsigned long sum = 0;
        for (unsigned long i = 1; i < n; ++i) {
            sum += i;
        }

        unsigned long expected_sum = n * (n + 1) / 2;
        if (sum != expected_sum) {
            throw std::runtime_error("Postcondition failed: sum does not match expected value. " +
                std::string("Error in file: ") + __FILE__ + " on line: " + std::to_string(__LINE__));
        }

        return sum;
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        throw; // Rethrow the exception to be handled by the caller
    }
}

int main() {
    try {
        std::cout << "sigma(5) = " << sigma(5) << std::endl; // Valid case
    } catch (const std::runtime_error& e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "sigma(0) = " << sigma(0) << std::endl; // Invalid case
    } catch (const std::runtime_error& e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

    return 0;
}
