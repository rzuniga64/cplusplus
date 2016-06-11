// FILE: Temperature.cpp
//       Definition file for the Temperatyure class
//       (See Temperature.h for documentation.)
//
// INVARIANT for the IntStore class:
// (1) Temperature value is stored as a double in member
//     variable 'temperature'.
// (2) Temperature scale value is stored as a char in member
//     variable 'scale'.
// (3) The values of the member variables are displayed using
//     const method 'display'.
// (4) The member variables can be modified using the method
//     'convert' which converts the temperature from the current
//     scale to the other scale.

#include "Temperature.h"
#include <iostream>
#include <cctype>
#include <typeinfo>

using namespace std;

Temperature::Temperature()
{
	temperature = 0.0;
	scale = 'F';
}

Temperature::Temperature(double temp, char sc) 
{
	if (typeid(temp)==typeid(double) && typeid(sc)==typeid(char))
	{
		temperature = temp;
		scale = sc;
	}
	else
		cout << "Invalid data type. Run the program\n"
			 << "again a enter a number for temperature and character for scale" << endl;
}

void Temperature::display() const
{
	cout << temperature << " " << scale;
}

void Temperature::convert()
{
	if (toupper(scale) == 'F') {
		temperature = (temperature - 32) * (5.0 / 9.0);
		scale = 'C';
	} 
	else if (toupper(scale) == 'C') {
		temperature = temperature * (9.0 / 5.0) + 32.0;
		scale = 'F';
	}
	else
		cout << "Incorrect temperature scale. Run the program\n"
			 << "again and enter a scale of F or C" << endl;

}
