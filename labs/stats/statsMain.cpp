#include <iostream>
#include <iomanip>
#include "stats.h"

using namespace std;

int main() {

	int choice;		// Menu choice
	double value;	// data to be stored
	Stats stats;

	do { // Display the menu and get the user's choice
		cout << endl << "Stats Menu" << endl << endl;
		cout << "1. Store a data value" << endl;
		cout << "2. Get the total of all data values" << endl;
		cout << "3. Get the average of the data values" << endl;
		cout << "4. Get the lowest data value" << endl;
		cout << "5. Get the highest data value" << endl;
		cout << "6. Quit the program " << endl;
		cin >> choice;

		// Validate the menu selection
		while ((choice <1) || (choice > 6)) {
			cout << "Please enter 1, 2, 3, 4, 5, or 6: ";
			cin >> choice;
		}

		// Process the user's choice
		switch (choice) {
		case 1: cout << "Enter data value to be stored: ";
				cin >> value;
				stats.storeValue(value);
				stats.display();
				break;
		case 2: cout << "The total is " << stats.total() << endl;
				break;
		case 3: cout << "The average is " << stats.average() << endl;
				break;
		case 4: cout << "The lowest value is " << stats.lowest() << endl;
				break;
		case 5: cout << "The highest value is " << stats.highest() << endl;
				break;
		}

	} while (choice != 6);  // Loop again if is user did not select choice 6

	return 0;
}

