#include "Customer.h"
#include <iostream>

using namespace std;

void selectionSort(Customer array[], const int size);

int main() {
	const int NUM_CUSTOMERS = 10;
	Customer customers[NUM_CUSTOMERS];
	ifstream inFile;
	inFile.open("customers.txt");

	for (int i=0; i<NUM_CUSTOMERS; i++)
		customers[i].read(inFile);

	cout << "Before sort: " << endl;
	for (int i=0; i<NUM_CUSTOMERS; i++)
		customers[i].display();

	// sort the array
	selectionSort(customers, NUM_CUSTOMERS);

	cout << endl << "After sort: " << endl;
	for (int i=0; i<NUM_CUSTOMERS; i++)
		customers[i].display();

	return 0;
}

void selectionSort(Customer array[], const int size) {
	int startScan, minIndex, minValue;
	Customer temp;

	for (startScan = 0; startScan < (size-1); startScan++)
	{
		minIndex = startScan;
		minValue = array[startScan].getAmountOwed();

		for (int index = startScan + 1; index < size; index++) {
			if (array[index].getAmountOwed() < minValue) {
				temp = array[index];
			}
		}
		array[minIndex] = array[startScan];
		array[startScan] = temp;
	}
}


