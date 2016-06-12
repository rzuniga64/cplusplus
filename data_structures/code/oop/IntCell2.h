#include <iostream>

using namespace std;

class IntCell2 {
public:
	// A default constructor is automaticall providede if
	// no constructors are provided by the programmer

	IntCell2(int initialValue = 0);
	// Copy Constructor
	IntCell2(const IntCell2 & rhs);
	// Destructor
	~IntCell2();

	int read() const;
	void write(int x);

	void operator=(const IntCell2 & rhs);
	bool operator==(const IntCell2 & rhs);

private:
	int *storedValue;
};