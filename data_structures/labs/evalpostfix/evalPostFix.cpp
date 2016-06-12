#include <iostream>
#include <string>
#include <algorithm>
#include "stack_3358.h"

using namespace std;

//************************************************************************************
// eval: returns a value when a specific opeator operates on two numbers oon the stack_ll
// Preconditions: numbers on the stack_ll are integers.
// Postconditions: the result of the operation on two numbers on the stack_ll

int performOperation(int num1, int num2, char operation) {
	switch (operation){
	case '*': return num2 * num1;
	case '/': return num2 / num1;
	case '+': return num2 + num1;
	case '-': return num2 - num1;
	default: return 0;
	}
}

//************************************************************************************
// isOperator: returns true if input is a '+', '-', '*', or '/'
// Preconditions: numbers on the stack_ll are integers.
// Postconditions: the result of the operation on two numbers on the stack_ll
bool isOperator(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		return true;
	else
		return false;
}

//************************************************************************************
// evalPostFix: evaluates the postfix express. It supports multiple digit integers
//				and looks for a valid expression.
// Preconditions: numbers on the stack_ll are integers.
// Postconditions: the result of the operation on two numbers on the stack_ll

bool evalPostFix(Stack_3358<int>  & stack,  const string expression) {
	bool isExprValid = false;
	char ch, buffer[15];
	int op1, op2, len;
	int index = 0;
	int stackSize = 0;

	len = expression.length();
	if (len == 0) {
		cout << "The expression " << expression << " is not a well-formed postfix expression" << endl;
	}

	for (int i = 0; i < len; i++) {
		ch = expression[i];

		if (isdigit(ch)) {
			//save each digit in a buffer until a space is found
			buffer[index++] = ch;
		}  
		if (!isdigit(ch) && index > 0) {
			// a space is found and there is a operand in the buffer
			// convert the operand to an integer and push it onto the stack_ll
			buffer[index] = '\0';
			stack.push(atoi(buffer));
			stackSize++;
			index = 0;
		} 
		if (isOperator(ch)) {
			// an operator was found so pop the top two
			// operands from the stack_ll and evaluate them
			// using the operator.
			if (stackSize > 1) {
				op1 = stack.pop();
				stackSize--;
				op2 = stack.pop();
				stackSize--;
			} else {
				stackSize = -1;
				cout << "The expression " << expression << " is not a well-formed postfix expression" << endl;
				break;
			}
	 
			// push the value obtained after evaluating the expression onto the stack_ll
			stack.push(performOperation(op1, op2, ch));
			stackSize++;
		} 
		if (!isOperator(ch) && !isdigit(ch) && !isspace(ch)) {
			stackSize = -1;
			cout << "The expression " << expression << " is not a well-formed postfix expression" << endl;
			break;
		}
	}

	if (stackSize == 1) {
		isExprValid = true;
	} else if (stackSize > 1) {
		cout << "The expression " << expression << " is not a well-formed postfix expression" << endl;
	}

	return isExprValid;
} 

int main() {

	string expression;
	int value;
	Stack_3358<int> stack;

	cout << "\nEnter postfix expression for evaluation (e.g. 20 3 1 * + 9 - returns 14):";

	getline(cin, expression);
	if (evalPostFix(stack, expression)) {
		value = stack.pop();
		printf("Answer is %d\n", value);
	}

	return 0;
}