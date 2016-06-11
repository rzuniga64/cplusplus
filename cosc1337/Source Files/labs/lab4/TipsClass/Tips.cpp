// FILE: Tips.cpp
//       Definition file for the Tips class
//       (See Tips.h for documentation.)
//
// INVARIANT for the Tips class:
// (1) Tax rate value is stored as a double in member
//     variable 'taxRate'.
// (2) The value of the member variable is displayed using
//     const method 'display'.
// (3) The tip amount is calculated by applying the to the
//	   total bill amount plus tax.

#include "Tips.h"
#include <iostream>

using namespace std;

Tips::Tips(double rate) {
	if (rate >= 0)
		taxRate = rate;
	else
		taxRate = 0.065;
}	

void Tips::display() const {
	cout << taxRate;
}

double Tips::computeTips(double totalBillAmount, double tipRate) {

	return ((totalBillAmount + totalBillAmount * taxRate)*tipRate);
}



