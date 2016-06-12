 #ifndef _IntCell_H_
#define _IntCell_H_
class IntCell
{
public:
	// Initial value is initialValue. 
	// 1. Constructor has an optional parameter. 
	// If no argument is specified, initialValue will be 0.
	// 3. Initializer list placed before the constructor body.
	// 4. Explicit constructor applies to one-argument constructors only.
	explicit IntCell(int initialValue = 0) :storedValue(initialValue) {}

	int read() const;  // 2. const member function, signifies function is an accessor

	void write(int);

	// The Big Three: destructor, copy constructor, operator=
	// When do the defaults not work?
	// Generally, when one of the members is dynamically allocated 
	// by the class (via a pointer).
private:
		int storedValue;
};

#endif