#include <iostream>
#include <string>
#include <assert.h>

using namespace std;
/***********************************************
TYPE INDEPENDENCE

Many algorithms like search, sort, or swap do
not depend on the type of the elements/items.
We would like to re - use the same code
regardless of the item type.

GENERIC PROGRAMMING

-	Writing functions and classes that are
type-independent is called generic programming.
-	These functions and classes will have an extra
-	parameter to represent the specific type of the
-	components.
-	When the stand-alone function is called, or
class is instantiated, the programmer provides
the specific type:

vector<string> students(20);
vector<double> dailySales(365);

Note: vector is a templated class.

TEMPLATES

-	C++ provides templates to implement generic
	functions and classes.
-	A function template is not a function, it is a
	design or pattern for a function.
-	The function template makes a function when
	the compiler encounters a call to the function.
-	Like a macro, it substitutes the appropriate type for
	the type variable.

Normal syntax to call the templated function
includes the type in angled brackets: <int>

	FUNCTION TEMPLATES
-	The compiler will not use (compile) the pattern
	unless/until it encounters a call to the function.
-	At that point, the compiler substitutes your type for
	the type variable, and then compiles the newly
	generated function as if you’d written the function
	that way yourself.

	CLASS TEMPLATES
	Template classes work similarly to template
	functions with the following exceptions
-	The compiler will never guess at type argument for a
	template class, you must always use <…> during
	object declaration.
-	Classes cannot be “overloaded”, but the compiler will
	permit you to instantiate the same template class in
	multiple ways. Each distinct instantiation results 
	in a completely distinct class!
	(with its own copy of the static data members, for example).
-	The member functions in a template class are
	template functions
*************************************************/


template <typename T>
void swapp(T &lhs, T &rhs) {
	T tmp = lhs;
	lhs = rhs;
	rhs = tmp;
}

// Object: must have default constructor and operator=
template <class Object>
class MemoryCell {
public:
	// Construct a MemoryCell.
	MemoryCell(const Object & initVal = Object())
		: storedValue(initVal) { }
	// public methods
	Object read()
	{
		return storedValue;
	}
	void write(Object x)
	{
		storedValue = x;
	}
private:
	Object storedValue; //stores the memory cell contents
};

template <typename T>
class vector {
public:
	vector(int initial_capacity = 8);
	void push_back(T);
	T pop_back();
	T operator[](int k);
private:
	T* data; //stores data in dynamically allocated array
	int length; //number of elements in vector
	int capacity; //size of array, to know when to expand
	void expand(); //to increase capacity as needed
};

template <typename T>
vector<T>::vector(int init_cap) {
	capacity = init_cap;
	data = new T[capacity];
	length = 0;
}

template <typename T>
void vector<T>::push_back(T x) {
	if (capacity == length)
		expand();
	data[length] = x;
	length++;
}

template <typename T>
T vector<T>::pop_back() {
	assert(length > 0);
	length--;
	return data[length];
}

template <typename T>
T vector<T>::operator[](int k) {
	assert(k >= 0 && k<length);
	return data[k];
}
template <typename T>
void vector<T>::expand(void) {
	capacity *= 2;
	T* new_data = new T[capacity];
	for (int k = 0; k < length; k += 1)
		new_data[k] = data[k];
	delete[] data;
	data = new_data;
}

int main() {
	int x = 5;
	int y = 7;
	string a = "hello";
	string b = "there";
	swapp <int>(x, y);		//int replaces Object
	swapp <string>(a, b);	//string replaces Object
	cout << x << " " << y << endl;
	cout << a << " " << b << endl;

	MemoryCell<int> m;
	m.write(5);
	cout << "Cell contents are " << m.read() << endl;
	MemoryCell<string> s;
	s.write("five");
	cout << "Cell contents are " << s.read() << endl;

	vector<string> v(2);
	v.push_back("As");
	v.push_back("Ks");
	v.push_back("Qs");
	v.push_back("Js");
	for (int i = 0; i<4; i++) {
		cout << v[i] << endl;
	}

	return 0;
}