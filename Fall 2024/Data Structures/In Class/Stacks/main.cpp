#include "ACStack.h"
#include <iostream>
using namespace std;

int main(){
    ACStack mystack(5);
    mystack.push('C');
    mystack.push('H');
    mystack.push('A');
    mystack.push('P');
    cout << mystack.peek() << endl;
    while(!mystack.isEmpty()){
        cout << mystack.pop() << endl;
    }
}