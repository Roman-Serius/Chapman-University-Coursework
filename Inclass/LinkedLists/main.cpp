#include <iostream>
#include "ListQueue.h"

int main() {
    // Create a Queue of integers
    Queue<int> myQueue;

    // Add elements to the queue
    std::cout << "Adding elements to the queue..." << std::endl;
    myQueue.add(10);
    std::cout << myQueue.peek() << std::endl;
    myQueue.add(20);
    std::cout << myQueue.peek() << std::endl;
    myQueue.add(30);
    std::cout << myQueue.peek() << std::endl;
    // Display the size of the queue
    std::cout << "Queue size: " << myQueue.getSize() << std::endl;

    // Remove and display the front element
    std::cout << "Popped element: " << myQueue.pop() << std::endl;

    // Display the size of the queue after pop
    std::cout << myQueue.peek() << std::endl;
    std::cout << "Queue size after pop: " << myQueue.getSize() << std::endl;

    // Check if the queue is empty
    if (myQueue.isEmpty()) {
        std::cout << "Queue is empty." << std::endl;
    } else {
        std::cout << "Queue is not empty." << std::endl;
    }

    return 0;
}