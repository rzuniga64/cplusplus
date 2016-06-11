// FILE: TipsMain.cpp
// A test program for the Tips class.

#include "Tips.h"
#include <iostream>		// Needed for cin, cout
#include <iomanip>		// Needed for setfill, setwidth
#include <stdlib.h>		// Needed for atof
#include <string>

using namespace std;

// Purpose: Determines if a string is a number
//          Only allow digits, period and hyphen.
// Input  : A string
// Output : True if the string is a number, false otherwise.

bool isNum(char * s) {
	bool flag = false;
	int i = 0;

	while(s[i]) {
		if (isalpha(s[i]) || (ispunct(s[i]) && s[i] != '.' && s[i] != '-')) {
			flag = false;
			break;
		} else
			flag = true;
		i++;
	}
	return flag;
}

// Purpose: Reads in the total bill amount and tax rate
//          and validates if the data entered is valid.
// Input  : the total bill amount and tax rate as strings
//			read in from the console.
// Output : None.  The totalBillAmount and tipRate are modified
//          if the data entered is valid.

void getUserInput(double &totalBillAmount, double &tipRate) {
	char num1[10], num2[10];
	bool valid;

	do {
		cout << "Please enter the total bill amount followed by the tip rate (0 0) to quit: ";
		cin >> num1 >> num2;
		if (isNum(num1) && isNum(num2)) {
			totalBillAmount = atof(num1);
			tipRate = atof(num2);
			valid = true;
		}
		else {
			cout << "Invalid bill amount or tip rate entered." << endl << endl;
			valid = false;
		}
	} while (!valid);
}

int main()
{
	const double taxRate = 0.0825;
	double totalBillAmount = -1.0, tipRate = -1.0, tip = 0.0;
	Tips t1(taxRate);

	getUserInput(totalBillAmount, tipRate);

	while (totalBillAmount != 0 || tipRate != 0) {
		if (totalBillAmount < 0 || tipRate < 0) {
			cout <<"You entered a number that is less than zero." << endl << endl;
		}
		else {
			tip = t1.computeTips(totalBillAmount, tipRate);
			cout << showpoint << setprecision(2) << fixed;
			cout << "The tip on $" << totalBillAmount << " with tax rate of " << setprecision(4);
			t1.display();
			cout << setprecision(3) << " and a tip rate of " << tipRate << setprecision(2) << " is $" << tip << endl << endl;
		}

		getUserInput(totalBillAmount, tipRate);
	}

	cout << "Exiting the program!" << endl;

	return 0;
}
