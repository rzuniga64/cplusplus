// This program illustrates a problem that can occur if
// cin is used to read character data into a string object.

// When cin reads data it passes over and ingnores any leading
// whitespace characters(spaces, tabs, or line breaks).  However,
// once it comes to the first nonblank character and starts
// reading, it stops reading, when it gets to the next whitespace
// character.

#include <iostream>
#include <string> // Header file needed to use string objects
using namespace std;

int main()
{
	string name;
	string city;

	cout << "Please enter your name: ";
	cin >> name;
	cout << "Enter the city you live in: ";
	cin >> city;

	cout << "Hello, " << name << endl;
	cout << "You live in " << city << endl;
	return 0;
}

