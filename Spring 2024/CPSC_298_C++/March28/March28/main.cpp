//
//  main.cpp
//  March28
//
//  Created by Soren on 3/28/24.
//

#include <iostream>

class CUltimateMachine
{
public:
    CUltimateMachine() : m_bState(false)
    {
        std::cout<< "CUltimate constructor (ctor) called" << std::endl;
    }
    ~CUltimateMachine()
    {
        std::cout << "CUltimateMachine destructor (dtor) called" << std::endl;
    }
    
    void displayState()
    {
        if (m_bState == true)
        {
            std::cout << "Ultimate Machine is ON" << std::endl;
        }
        else
        {
            std::cout << "Ultimate Machine is Off" << std::endl;
        }
    }
    
    void turnOn()
    {
        m_bState = true;
        displayState();
        if (true == m_bState)
        {
            m_bState = false;
        }
        displayState();
    }
    
private:
    bool m_bState;
};

int main()
{
    std::cout << "The Ultimate Machine Simulation" << std::endl;
    
    CUltimateMachine ultmach;
    ultmach.displayState();
    ultmach.turnOn();
}


