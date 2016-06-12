// File name: stack_test.cpp
//
// tests a Stack ADT
//

#include <iostream>
#include "stack_3358_ll.h"

using namespace std;

template <typename itemType>
void showStack(Stack_3358 <itemType> temp);

int main () {
    
    Stack_3358 <int> myStack;   //stack of ints
    
    Stack_3358 <char> s;        //stack of chars
    
    if (myStack.isEmpty())
        cout << "int stack is empty" << endl;
    else
        cout << "int stack is not empty" << endl;   
    
    s.push('Y');
    cout << "The char stack: " << endl;
    showStack(s);
    
    myStack.push(42);
    
    
    if (myStack.isEmpty())
        cout << "int stack is empty" << endl;
    else
        cout << "int stack is not empty" << endl;   
    
    myStack.push(52);
    
    myStack.push(12);
    
    cout << "test pushes to int stack" << endl;  
    showStack(myStack);
    
    Stack_3358 <int> myStack2 = myStack; //copy constructor
    
    myStack.pop();
    
    myStack.pop();
    
    cout << "test pops from original int stack" << endl;  
    showStack(myStack);
    
    cout << "show copied Stack, tests copy constructor" << endl;
    showStack(myStack2);
    
}   


//prints Stack.

template <typename itemType>
void showStack(Stack_3358 <itemType>  temp) {  //uses copy constr!!
    
    cout << "stack from top " << endl;
    while (!temp.isEmpty()) {
        cout << temp.pop() << endl;
        
    }
    cout << endl;
    
}


