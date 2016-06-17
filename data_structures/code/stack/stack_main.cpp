#include <iostream>
#include <string>
#include "stack.h"

template <typename T>
void showStack(stack<T> temp);

int main() {

	stack<string> myStack;

	if (myStack.isEmpty())
		cout << "int stack is empty" << endl << endl;
	else
		cout << "int stack is not empty" << endl << endl;
	
	myStack.push("roy");
	myStack.push("randy");
	myStack.push("justin");
	
	if (myStack.isEmpty())
		cout << "int stack is empty" << endl << endl;
	else
		cout << "int stack is not empty" << endl << endl;
	
	stack<string> myStack2 = myStack;
	
	cout << "test pops from original int stack" << endl;
	myStack.pop();
	showStack(myStack);
	
	cout << "show copied Stack, tests copy constructor" << endl;
	showStack(myStack2);

	myStack2.makeEmpty();
	showStack(myStack2);
	
	return 0;
}

template <typename T>
void showStack(stack<T> temp){
	cout << "stack from top" << endl;
	while (!temp.isEmpty())
		cout << temp.pop() << " " << endl;
	cout << endl;
}