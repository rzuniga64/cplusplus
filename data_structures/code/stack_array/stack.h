/*
	Stack: a data structure that holds a collection of
	elements of the same type.
	- The elements are accessed according to LIFO
	order: last in, first out
	- No random access to other elements

	STACK OPERATIONS
	Operations:
	-	push: add a value onto the top of the stack
		-	make sure it’s not full first.
	-	pop: remove (and return) the value from the top of the stack
		-	make sure it’s not empty first.
	-	isFull: true if the stack is currently full, i.e.,has no
		more space to hold additional elements
	-	isEmpty: true if the stack currently contains no elements

		These operations should take constant time: O(1).

	-	makeEmpty: removes all the elements 
		This is allowed to take longer than constant time.

		Stack overflow:
		- trying to push an item onto a full stack

		Stack underflow.
		- trying to pop an item from an empty stack

		IMPLEMENTING A STACK CLASS
		
		Array implementations:
		- fixed arrays: size doesn’t change
		- dynamic arrays: can resize as needed in push
		
		Linked List
		- grow and shrink in size as needed
*/

#include <assert.h>

using namespace std;

template <typename T>
class stack {
public:
	stack();
	bool isEmpty() const;
	bool isFull() const;
	void makeEmpty();
	void push(T value);
	T pop();
private:
	static const int SIZE = 100;	// the stack size
	T mystack[SIZE];
	int top;
};

template <typename T> 
stack<T>::stack() {
	// no need to initialize the static array stack.
	top = -1;	//empty
}

//	isEmpty: Returns true if the stack is empty, false otherwise.
template <typename T>
bool stack<T>::isEmpty() const {
	return (top == -1);
}

//	isFull: Returns true if the stack is full, false otherwise.
template <typename T>
bool stack<T>::isFull() const{
	return (top == SIZE - 1);
}

// Makes the stack an empty stack
template <typename T>
void stack<T>::makeEmpty() {
	top = -1;
}

//	push: Member function pushes the argument onto the stack
template <typename T>
void stack<T>::push(T value) {
	// make sure it’s not full first.
	assert(!isFull());
	top++;
	mystack[top] = value;
}

//	pop: Pops the value at the top of the stack off, and returns it.
template <typename T>
T stack<T>::pop(){
	// make sure it’s not empty first.
	assert(!isEmpty());
	T temp = mystack[top];
	top--;
	return temp;
}

