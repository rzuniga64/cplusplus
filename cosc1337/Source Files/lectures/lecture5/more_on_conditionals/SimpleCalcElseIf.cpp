// SimpleCalc1.cpp
// Takes two numeric inputs, and an operation to perform on them
// performs the operation and displays the output
// Written by Sarah Finney for COSC1315 Lecture 11

#include <iostream>

using namespace std;

int main() {
    char operationToDo = ' ';
    double num1 = 0.0;
    double num2 = 0.0;
    double output = 0.0;
    
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    cout << "Enter operation to perform: ";
    cin >> operationToDo;
        
    if (operationToDo == '+' || operationToDo == 'a' || operationToDo == 'A') {
        output = num1 + num2;
    }
    else if (operationToDo == '-') {
        output = num1 - num2;
    }
    else if (operationToDo == '*') {
        output = num1 * num2;
    }
    else if (operationToDo == '/') {
        output = num1 / num2;
    }
    else {
        cout << "Error: invalid operation." << endl;
    }
    cout << "Result: " << output << endl;
    system("PAUSE");
    return 0;
}
