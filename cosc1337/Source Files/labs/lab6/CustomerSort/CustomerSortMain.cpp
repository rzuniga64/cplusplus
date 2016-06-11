// FILE: CustomerSortMain.cpp
// A test program for the Customer class.

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

/**************************************************************
* selectionSort *
* This function performs an descending-order selection sort *
* on array. The parameter size holds the number of elements *
* in the array. *
**************************************************************/

void selectionSort(Customer array[], const int size) {
	int startScan, maxIndex, maxValue;
	Customer temp;

	for (startScan = 0; startScan < (size-1); startScan++)
	{
		maxIndex = startScan;
		maxValue = array[startScan].getAmountOwed();

		for (int index = startScan + 1; index < size; index++) {
			if (array[index].getAmountOwed() > maxValue) {
				maxValue = array[index].getAmountOwed();
				maxIndex = index;
			}
		}
		temp = array[maxIndex];
		array[maxIndex] = array[startScan];
		array[startScan] = temp;
	}
}
