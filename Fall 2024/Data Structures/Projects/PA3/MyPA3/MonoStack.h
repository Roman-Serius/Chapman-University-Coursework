//Soren Marius
//002456139
//Marius@chapman.edu
//CPSC-350-01
//PA3: Do You See What I See?

#ifndef MONOSTACK_H
#define MONOSTACK_H

#include <iostream>



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

// Implementation of the templated class

template <typename T>
MonoStack<T>::MonoStack(int size, char o) : capacity(size), topIndex(-1), mode(o) {
    stackArray = new T[capacity];
}

template <typename T>
MonoStack<T>::~MonoStack() {
    if(stackArray != nullptr){
    delete[] stackArray;
    }
}

template <typename T>
bool MonoStack<T>::isEmpty() {
    return topIndex == -1;
}

template <typename T>
bool MonoStack<T>::isFull() {
    return topIndex == capacity - 1;
}

template <typename T>
void MonoStack<T>::push(T value) {
    

    while (!isEmpty() && ((mode == 'i' && stackArray[topIndex] > value) || (mode == 'd' && stackArray[topIndex] < value))) {
        pop();
    }

    push(value);
    
    
}

template <typename T>
void MonoStack<T>::pop() {
    
    topIndex--;
}

template <typename T>
T MonoStack<T>::top() {
    
    return stackArray[topIndex];
}

#endif