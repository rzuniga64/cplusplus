#include "ArrayFunctions.h"

int main()
{

	/* Pseudocode for algorithm:

	declare/initialize integer pointer variable
	(and other necessary variables)

	do
	read in array size
	deallocate old array if necessary
	allocate new array
	read in array values (use function)
	sort array (use function)

	read in item to find percentile for
	while item is positive
	calculate and display percentile (use function)
	read in item to find percentile for
	end while
	while user wants to continue
	deallocate old array if necessary
	*/

	int * numbers = NULL;
	int size, value;
	double percentile;
	char answer = 'y';

	do {
		cout << "Enter array size: ";
		cin >> size; 

		delete[] numbers;
		numbers = new int[size];
		readArray(numbers, size);
		sortArray(numbers, size);

		cout << "Enter value for which to find percentile: ";
		cin >> value;

		while (value > 0) {
			percentile = getPercentile(numbers, size, value);
			cout << "Percentile of value: " << percentile << endl;
			cout << "Enter value for which to find percentile: ";
			cin >> value;
		}

		cout << endl <<"Enter a new array(y / n): ";
		cin >> answer;

	} while (tolower(answer) == 'y');
}
