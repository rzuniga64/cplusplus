// This program calculates the area of a circle. The formula for the
// area of a circle is PI times the radius squared. PI is 3.14159.

// Constant variables are defined like regular variables.  They have a
// data type and a specific storage location in memory.

#include <iostream>
#include <cmath> // Needed for the pow function
using namespace std;

int main()
{
	const double PI = 3.14159; // PI is a named constant
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

