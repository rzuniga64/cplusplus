#include "IntCell2.h"

// The big three: destructor, copy constructor, operator=
// When do the defaults not work ?
// Generally, when one of the members is dynamically allocated by the class 

// Constructor
IntCell2::IntCell2(int initialValue){
	storedValue = new int;
	*storedValue = initialValue;
}

// Copy constructor
IntCell2::IntCell2(const IntCell2 &rhs) {
	storedValue = new int;
	*storedValue = rhs.read();
}

// Destructor
IntCell2::~IntCell2() {
	delete storedValue;
}

int IntCell2::read() const {
	return *storedValue;
}

void IntCell2::write(int x) {
	*storedValue = x;
}

// overloaded assignment operator
void IntCell2::operator=(const IntCell2 & rhs) {
	*storedValue = rhs.read();
}

// overloaded equals operator
bool IntCell2::operator==(const IntCell2 & rhs) {
	return *storedValue == rhs.read();
}