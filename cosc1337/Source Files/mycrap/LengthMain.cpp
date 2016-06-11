#include "Length.h"

int main() {
	Length * lenPtr = NULL;
	double value;
	string units, newUnits;

	cout << "Enter a length (negative to quit): ";
	cin >> value;
	while(value >= 0) {
		cout << "Enter the original units (cm/inches/feet): ";
		cin >> units;
		if (lenPtr)
			delete lenPtr;
		lenPtr = new Length(value, units);
		cout << "Enter the new units (cm/inches/feet): ";
		cin >> newUnits;
		lenPtr->convertTo(newUnits);
		cout << "Converted length: ";
		lenPtr->display();
		cout << "Enter a length (negative to quit): ";
		cin >> value;
	}
	
    return 0;
}
