#ifndef STACKDYNAMICARRAY_H
#define STACKDYNAMICARRAY_H

/*
	Stack: a data structure that holds a collection of elements of the same type.
	- The elements are accessed according to LIFO, order: last in, first out
	- No random access to other elements

	STACK OPERATIONS
	Operations: These operations should take constant time: O(1).
 	-	isFull: true if the stack is currently full, i.e.,has no more space to hold additional elements
	-	isEmpty: true if the stack currently contains no elements
	-	push: add a value onto the top of the stack. Make sure it is not full first.
	-	pop: remove (and return) the value from the top of the stack. Make sure it is not empty first.
	-	Stack overflow: trying to push an item onto a full stack
	-	Stack underflow. trying to pop an item from an empty stack

		This operations should take constant time: O(n).
	-	makeEmpty: removes all the elements

		IMPLEMENTING A STACK CLASS

		Array implementations:
		- fixed arrays: size doesn't change
		- dynamic arrays: can resize as needed in push
		- Linked List: grow and shrink in size as needed
*/

template <typename T>
class StackDynamicArray {
public:
    StackDynamicArray();
    ~StackDynamicArray();
    StackDynamicArray(const StackDynamicArray & src)

    bool isFull() const;
    bool isEmpty() const;
    void makeEmpty();
    void push(T value);
    T pop();
private:
    static const int SIZE=100;
    T * mystack;
    int top;
    int size;
};

template <typename T>
StackDynamicArray<T>::StackDynamicArray() :
        size(SIZE) {
    top = -1; //empty
    mystack = new T[size];
}

template <typename T>
StackDynamicArray<T>::~StackDynamicArray()
{
    delete[] mystack;
}

template<typename T>
StackDynamicArray<T>::StackDynamicArray(const StackDynamicArray & src) {
    mystack = new T[src.size];
    size = src.size;
    for (int i = 0; i < top; i++) {
        mystack[i] = src.mystack[i];
    }
}

template <typename T>
bool StackDynamicArray<T>::isFull() const
{
    return (top == SIZE - 1);
}

template <typename T>
bool StackDynamicArray<T>::isFull() const
{
    return (top == SIZE - 1);
}


template <typename T>
void StackDynamicArray<T>::makeEmpty()
{
    top = -1;
}

template <typename T>
void StackDynamicArray<T>::push(T value) {
    if (top == size)
        size *= 2;
    T newStack = new T[size];
    for (int i = 0; i < top; i++) {
        newStack[i] = mystack[i];
        delete mystack;
        mystack = newStack;
        top++;
        mystack[top] = value;
    }
}

#endif
