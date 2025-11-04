#ifndef LIST_QUEUE_H
#define LIST_QUEUE_H

#include "DblList.h"

template<typename T>
class Queue{
    public:
    Queue();
    virtual ~Queue();
    int getSize();
    bool isEmpty();
    T pop();
    void add(T data);
    T peek();
    private:
    DblList<T> List;
    




    
};
template<typename T>
Queue<T>::Queue() {
    List = DblList<T>();    
}

template<typename T>
Queue<T>::~Queue() {
    

}
template<typename T>
int Queue<T>::getSize() {
    return List.getSize();  
}
template<typename T>
bool Queue<T>::isEmpty() {
    return List.isEmpty();  
}


template<typename T>
T Queue<T>::pop() {
    T frontElement = List.get(0);  
    List.removeFront();                
    return frontElement;
}


template<typename T>
void Queue<T>::add(T data) {
    List.addBack(data);  
}

template<typename T>
T Queue<T>::peek(){
    return List.get(0);
}


#endif