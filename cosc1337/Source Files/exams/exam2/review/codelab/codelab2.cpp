#include <iostream>

using namespace std;

bool insertionSort(int a[], int size, bool abool)
{	bool isSorted = true;
	if (abool) {
		for (int i=0; i<size-1; i++) {
			if (a[i+1] < a[i])
				isSorted = false;
		}
	} else if (!abool) {
		for (int i=0; i< size-1; i++) {
			if (a[i+1] > a[i])
				isSorted = false;
		}
	}
	return isSorted;
}

int main() {

	const int size =5;
	int a[size] = { 13, 10, 8, 5, 2 };
	int interest = 2;
	bool isSorted = false;

	insertionSort(a, size, isSorted);

	return 0;
}
