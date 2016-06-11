#include <iostream>

using namespace std;

void reverse(int array[], int size)
{
	int temp;
	for (int i=0; i < size/2; i++){
		temp = array[i];
		array[i] = array[size -1 -i];
		array[size -1 - i] = temp;
	}

}

int main() {
	bool isReversed;
	const int size = 7;
	int arr[size] = { 0, 1, 2, 3, 4, 5, 6};
	reverse(arr, size);

	for (int i=0; i < size; i++)
		cout << arr[i] << " ";

	return 0;
}
