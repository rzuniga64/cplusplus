#include <iostream>

using namespace std;

bool isReverse(int arr1[],int arr2[], int size)
{
	bool isReverse = true;

	for (int i = 0; i < size; i++)
	{
		cout << arr1[i] << " " << arr2[(size-1) -i] << endl;
		if (arr1[i] != arr2[(size-1) -i])
			isReverse = false;
	}
	return isReverse;
}

int main() {

	bool isReversed;
	const int size = 3;
	int arr1[3] = { 0, 1, 2 };
	int arr2[3] = { 2, 1, 0 };
	isReversed = isReverse(arr1, arr2, size);
	return 0;
}
