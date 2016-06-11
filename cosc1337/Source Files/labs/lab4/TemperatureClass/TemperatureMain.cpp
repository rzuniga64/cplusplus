// FILE: TemperatureMain.cpp
// A test program for the Temperature class.

#include "Temperature.h"
#include <iostream>

using namespace std;

int main()
{
	Temperature t1;				// calls the default constructor
	t1.display();				// tests the constructor and display function

	Temperature t2(212, 'F');	// calls the second constructor
	cout << endl << "original t2: ";
	t2.display();				// tests the second constructor

	cout << endl;
	t2.convert();				// calls the convert function
	cout << "converted t2: ";
	t2.display();				// tests the convert function

	cout << endl;				// test the constructor with invalid scale
	Temperature t3(0, 'J');
	t3.display();

	Temperature t4(32, 'F');
	cout << endl << "original t4: ";
	t4.display();

	cout << endl;
	t4.convert();				// calls the convert function
	cout << "converted t4: ";
	t4.display();				// tests the convert function
	return 0;
}
