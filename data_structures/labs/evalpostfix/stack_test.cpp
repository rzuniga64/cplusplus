// File name: stack_test.cpp
//
// tests a Stack ADT
//

#include <iostream>
#include "stack_3358.h"

using namespace std;

void showStack(Stack_3358<int> temp);

int main() {

	Stack_3358<int> myStack;   //stack_ll of ints


	if (myStack.isEmpty())
		cout << "int stack_ll is empty" << endl;
	else
		cout << "int stack_ll is not empty" << endl;

	myStack.push(42);

	if (myStack.isEmpty())
		cout << "int stack_ll is empty" << endl;
	else
		cout << "int stack_ll is not empty" << endl;

	myStack.push(52);

	myStack.push(12);

	cout << "test pushes to int stack_ll" << endl;
	showStack(myStack);

	Stack_3358<int> myStack2 = myStack; //copy constructor

	myStack.pop();

	myStack.pop();

	cout << "test pops from original int stack_ll" << endl;
	showStack(myStack);

	cout << "show copied Stack, tests copy constructor" << endl;
	showStack(myStack2);

	myStack2.makeEmpty();
	showStack(myStack2);

	return 0;
}


//prints Stack.

void showStack(Stack_3358<int> temp) {  //uses copy constr!!

	cout << "stack_ll from top " << endl;
	while (!temp.isEmpty()) {
		cout << temp.pop() << endl;

	}
	cout << endl;

}