//Soren Marius
//002456139
//Marius@chapman.edu
//CPSC-350-01
//PA3: Do You See What I See?

#ifndef MONOSTACK_H
#define MONOSTACK_H

#include <stdexcept>

template <typename T>
class MonoStack {
private:
    T* stackArray;
    int topIndex;
    int capacity;
    char mode; // 'i' for increasing, 'd' for decreasing

public:
    MonoStack(int size, char o);
    ~MonoStack();
    
    bool isEmpty();
    bool isFull();
    void push(T value);
    void pop();
    T top();
};

#include "MonoStack.cpp"  // Include the implementation file to prevent linker errors

#endif
