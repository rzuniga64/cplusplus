/*
 * 	Purpose: Produce a bar chart showing teh population growth of Prairieville,
 * 			 a small town in the Midwest, at 20 year intervals during the past
 * 			 100 years.
 * 	Input: 	 The population figures (rounded to the nearest 100 people) for
 * 			 1900, 1920, 1940, 1960, 1980 and 2000 from a file.
 * 	Output:	 for each year it should display the data and a bar consisting of one
 * 			 asterisk for each 1000 people.  The data can be found in the people.txt
 * 			 file.
 *
 * 			 PRAIRIEVILL POPULATION GROWTH
 * 			 (each * represents 1000 people
 *
 * 			 1900 **
 * 			 1920 ****
 * 			 1940 *****
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	ifstream infile;
	int data = 0;
	string asterisks = " ";
	int numAsterisks = 0;
	int year = 1900;

	infile.open("people.txt");

	cout << "PRAIRIEVILLE POPULATION GROWTH" << endl;
	cout << "(each * represents 1000 people)" << endl << endl;

	// Loop through all the data in the file people.txt
	while (infile >> data)
	{
		// each bar will consists of asterisks. One '*' = 1000 people.
		// numAsterisks is of type int so a division will truncate the
		// remainder to get number of asterisks.
		numAsterisks = data/1000;
		asterisks.assign(numAsterisks, '*');
		cout << year << " " << asterisks << endl;
		year += 20;
	}
	return 0;
}
