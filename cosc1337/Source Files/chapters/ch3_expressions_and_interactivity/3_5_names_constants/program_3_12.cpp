// This program calculates the area of a circle. The formula for the
// area of a circle is PI times the radius squared. PI is 3.14159.

// Constants created with the #define directive are not variables at all.
// They are substitutions.  Each occurence of the named constant in your
// source code is removed and the value of the constant is written in its
// place when it is sent to the compiler.  Be carefull not to put a
// semicolon at the end of a #define directive.

#include <iostream>
#include <cmath> // Needed for the pow function
using namespace std;

#define PI 3.14159 // PI is "defined" to be 3.14159

int main()
{
	double area, radius;

	cout << "This program calculates the area of a circle.\n";

	// Get the radius
	cout << "What is the radius of the circle? ";
	cin >> radius;

	// Compute and display the area
	area = PI * pow(radius, 2);
	cout << "The area is " << area << endl;
	return 0;
}

