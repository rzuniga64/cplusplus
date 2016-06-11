#include "Sorter.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool isSorted(double * a, int size, bool ascending);

int main() {
	const int SIZE = 20;
	double numbers[SIZE];
	srand(time(0));
	for (int i=0; i<SIZE; i++)
 		numbers[i] = (rand() % 10000) * 0.01;

 	IncreasingSorter increase;
 	increase.sortArray(numbers, SIZE);
 	cout << isSorted(numbers, SIZE, true) << endl;

 	DecreasingSorter decrease;
 	decrease.sortArray(numbers, SIZE);
 	cout << isSorted(numbers, SIZE, false) << endl;

	return 0;
}


bool isSorted(double * a, int size, bool ascending) {
	bool okay = true;
	for (int i=0; i<size-1 && okay; i++) {
		if ((ascending && a[i] > a[i+1]) || (!ascending && a[i] < a[i+1]))
 			okay = false;
 	}
 	return okay;
 }

