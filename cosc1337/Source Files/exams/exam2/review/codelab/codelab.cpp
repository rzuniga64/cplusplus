#include <iostream>

using namespace std;

void insertionSort(int a[], int size)
{
	int toInsertIndex, toInsertValue, index;
	for (toInsertIndex = 1; toInsertIndex < size; toInsertIndex++)
	{	
		toInsertValue = a[toInsertIndex];
		index = toInsertIndex;
		while(a[index-1] > toInsertValue && index > 0)
		{
			a[index] = a[index-1];
			a[index-1] = toInsertValue;
			index--;
		}
		for (int i=0; i < size; i++)
			cout << a[i] << " ";
		cout << endl;
	}
}

int main() {

	const int size =5;
	int a[size] = { 8, 2, 13, 10, 5 };

	insertionSort(a, size);

	return 0;
}
