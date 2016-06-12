#include <iostream>
#include "IntCell.h"
#include "IntCell2.h"
#include "Storage.h"
#include "Month.h"

using namespace std;

int main() {
	// Encapsulation: combining data and code into a single object
	// Information hiding: ability to hide the details of data
	// representation from the code outside the object
	// Interface: the mechanism that code outside the object uses
	// to interact with the object. The prototype of the object's
	// public function.

	IntCell intcell(45);
	cout << "intcell = " << intcell.read() << endl;
	intcell.write(50);
	cout << "intcell = " << intcell.read() << endl;

	IntCell2 intcell2(35);
	IntCell2 intcell3(55);
	cout << "intcell = " << intcell2.read() << endl;
	cout << "intcell = " << intcell3.read() << endl;
	if (intcell2 == intcell3)
		cout << "intcell2 == incell3";

	intcell2 = intcell3;
	if (intcell2 == intcell3)
		cout << "intcell2 == incell3" << endl;

	// Composition is when one class contains another 
	// as a member
	Storage memory(10);	// calls Storage(int) constructor

	for (int i = 0; i < 10; i++) {
		memory.put(i, 2 * i);
	}

	cout << "Cell #4 contents: " << memory.get(3) << endl;

	Month month;
	Month::Day dayOfWeek = month.whatDayIsIt();

	cout << "Day of week is " << dayOfWeek;

	return 0;
}