// This program uses setw to display three rows of numbers so they align.
// Because the program uses setw(6), and the largest number has four
// digits, the numbers will be seperated without having to print a string
// literal containing blanks between the numbers;

#include <iostream>
#include <iomanip> // Header file needed to use setw
using namespace std;

int main()
{
	int num1 = 2897, num2 = 5, num3 = 837,
	num4 = 34, num5 = 7, num6 = 1623,
	num7 = 390, num8 = 3456, num9 = 12;

	// Display the first row of numbers
	cout << setw(6) << num1 << setw(6) << num2 << setw(6) << num3 << endl;

	// Display the second row of numbers
	cout << setw(6) << num4 << setw(6) << num5 << setw(6) << num6 << endl;

	// Display the third row of numbers
	cout << setw(6) << num7 << setw(6) << num8 << setw(6) << num9 << endl;

	return 0;
}

