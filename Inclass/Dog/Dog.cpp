#include "Dog.h"
#include <cstdlib>

Dog::Dog(){
    m_name = "";
    m_age = 0;
    m_owner = NULL;
}

Dog::Dog(string name, int age, string ownerName){
    m_name = name;
    m_age = age;
    m_owner = new Person(ownerName);
}

Dog::~Dog(){
    if(m_owner != NULL){
        delete m_owner;
    }
}

void Dog::speak(){
    cout << "Bark" << endl;
    cout << "I am " << m_age*7 << endl;
    cout << "I belong to " << m_owner->getName() << endl; 
}

string Dog::getName(){
    return m_name;
}

int Dog::getAge(){
    return m_age;
}

void Dog::setName(string name){
    m_name = name;
}

void Dog::setAge(string age){
    m_age = age;
}