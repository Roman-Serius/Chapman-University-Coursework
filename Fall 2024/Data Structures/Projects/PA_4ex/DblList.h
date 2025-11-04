//Soren Marius
//002456139
//Marius@chapman.edu
//CPSC-350-01
//PA4: Genetic Palindromes
#ifndef DBLLIST_H
#define DBLLIST_H

template <typename T>
class Node {
public:
    T data;
    Node *next;
    Node *prev;

    Node(T value) : data(value), next(nullptr), prev(nullptr) {}
};

template <typename T>
class DblList {
public:
    Node<T> *head;
    Node<T> *tail;

    DblList() : head(nullptr), tail(nullptr) {}
    ~DblList();

    void append(T value);
    T get(int index);
    int size();
};

template <typename T>
DblList<T>::~DblList() {
    Node<T> *current = head;
    while (current != nullptr) {
        Node<T> *nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

template <typename T>
void DblList<T>::append(T value) {
    Node<T> *newNode = new Node<T>(value);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

template <typename T>
T DblList<T>::get(int index) {
    Node<T> *current = head;
    for (int i = 0; i < index && current != nullptr; i++) {
        current = current->next;
    }
    return current ? current->data : T();
}

template <typename T>
int DblList<T>::size() {
    int count = 0;
    Node<T> *current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

#endif