// File name: stack_3358.h
//
// a Stack ADT
//
// This implentation uses a List_3358
// This implementation is a template


#include <assert.h>
#include <vector>
#include "list_3358.h"

using namespace std;

template<class ItemType>
class Stack_3358 {

public:

	//***********************************************************
	// Stack_3358: default constructor
	// Preconditions: None.
	// Postconditions: stack is empty.

	Stack_3358();

	//****************************
	// makeEmpty: Removes all the items from the stack.
	// Preconditions: None.
	// Postconditions: All the items have been removed

	void makeEmpty();

	//****************************
	// isEmpty: Checks to see if there are any items on the stack.
	// Preconditions: None.
	// Postconditions: Returns true if there are no items on the stack,
	//   else false.

	bool isEmpty() const;

	//****************************
	// isFull: Determines if you have any more room to add items to the stack.
	// Preconditions: None.
	// Postconditions: Returns true if there is no more room to add items,
	//   else false.

	bool isFull() const;

	//****************************
	// push: Adds newItem to the top of the stack.
	// Preconditions: Stack is not full.
	// Postconditions: newItem is at the top of the stack.

	void push(const ItemType &);

	//****************************
	// pop: Removes topItem from stack and returns it.
	// Preconditions: Stack is not empty.
	// Postconditions: Top element has been removed from stack and a copy of the
	//    removed element is returned.

	ItemType pop();

private:

	// insert the necessary member variable(s) here
	List_3358<ItemType> stack;
};

/*******************************
 / Function implementations
 ********************************/

template<class ItemType>
Stack_3358<ItemType>::Stack_3358 ()
{}

template<class ItemType>
void Stack_3358 <ItemType>::makeEmpty()
{
	//for (stack.resetBack(); !stack.isEmpty(); stack.backup()) {

	while (!stack.isEmpty()) {
		stack.resetBack();
		stack.remove();
		stack.backup();
	}
}

template<class ItemType>
bool Stack_3358 <ItemType>::isEmpty() const
{  
	return (stack.isEmpty());
}

template<class ItemType>
bool Stack_3358 <ItemType>::isFull() const
{
	return false;
}


template<class ItemType>
void Stack_3358 <ItemType>::push(const ItemType& newItem)
{
	assert(!isFull());
	stack.insert(newItem);
}


template<class ItemType>
ItemType Stack_3358 <ItemType>::pop()
{
	assert(!isEmpty());
	stack.resetBack();
	ItemType num = stack.getCurrent();
	stack.remove();
	return num;
}