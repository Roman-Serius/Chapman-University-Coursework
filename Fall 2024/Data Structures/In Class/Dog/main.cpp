#include "Dog.h"

int main(){
    Dog d1("Honor", 3,"Dr. Linstead"); //create object on the stack, statically allocated
    d1.speak();

    Dog* d2 = new Dog("Lilah", 4, "Dr. Stevens"); //create object on the heap, dynamically allocated
    d2->speak();
    delete d2;
    return 0;
}