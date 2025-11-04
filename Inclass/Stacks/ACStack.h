

#ifndef ACSTACK_H
#define ACSTACK_H

class ACStack{
    public:
        //ACStack();
        ACStack(int iSize);
        ~ACStack();
        void push(char c); //adds to top
        char pop();//removes and returns
        char peek();//returns doesn't remove
        bool isEmpty();
        bool isFull();
        int size();
    private:
        char* stackArr; //our Array to hold chars
        int maxSize; //max number of things in stack
        int top; //index of the current top of the stack
        int count; // number of items in stack
        
};


#endif