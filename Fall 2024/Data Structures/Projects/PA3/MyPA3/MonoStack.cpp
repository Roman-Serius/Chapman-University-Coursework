// #include "MonoStack.h"

// template <typename T>
// MonoStack<T>::MonoStack(int size, char o) : capacity(size), topIndex(-1), mode(o) {
//     stackArray = new T[capacity];
// }

// template <typename T>
// MonoStack<T>::~MonoStack() {
//     delete[] stackArray;
// }

// template <typename T>
// bool MonoStack<T>::isEmpty() {
//     return topIndex == -1;
// }

// template <typename T>
// bool MonoStack<T>::isFull() {
//     return topIndex == capacity - 1;
// }

// template <typename T>
// void MonoStack<T>::push(T value) {
//     if (isFull()) {
//         throw std::overflow_error("Stack overflow");
//     }

//     // Ensure the monotonic condition
//     while (!isEmpty() && ((mode == 'i' && stackArray[topIndex] > value) || (mode == 'd' && stackArray[topIndex] < value))) {
//         pop();
//     }

//     stackArray[++topIndex] = value;
// }

// template <typename T>
// void MonoStack<T>::pop() {
//     if (isEmpty()) {
//         throw std::underflow_error("Stack underflow");
//     }
//     topIndex--;
// }

// template <typename T>
// T MonoStack<T>::top() {
//     if (isEmpty()) {
//         throw std::underflow_error("Stack is empty");
//     }
//     return stackArray[topIndex];
// }