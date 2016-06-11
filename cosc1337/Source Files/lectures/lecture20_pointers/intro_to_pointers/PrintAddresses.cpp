// PrintAddresses.cpp
// Declares several variables and prints their memory
// addresses.
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	bool boolVar = false;
	double doubleVar = 15.0;
	int intVar = 42;

	cout << "address of boolVar: " << &boolVar << endl;
	cout << "address of doubleVar: " << &doubleVar << endl;
	cout << "address of intVar: " << &intVar << endl;

	system("PAUSE");
	return 0;
}
