#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int> &vect)
{
	unsigned int startScan;
	int minIndex, minValue;

	for (startScan = 0; startScan < vect.size()-1; startScan++)
	{
		minIndex = startScan;
		minValue = vect[startScan];
		for (unsigned int index = startScan + 1; index < vect.size(); index++)
		{
			if (vect[index] < minValue)
			{
				minValue = vect[index];
				minIndex = index;
			}
		}
		vect[minIndex] = vect[startScan];
		vect[startScan] = minValue;
	}
}

int binarySearch(const vector<int> &vect, int value)
{
	int first = 0,
		last = vect.size() - 1,
		middle, 
		position = -1;
	bool found = false;

	while (!found && first <= last) 
	{
		middle = (first + last) / 2;
		if (vect[middle] == value)
		{
			found = true;
			position = middle;
		}
		else if (vect[middle] > value)
			last = middle - 1;
		else
			first = middle + 1;
	}
	return position;
}

int main() 
{

	vector<int> numbers;
	int value;

		cout << "Enter a positive number(negative number to quit): ";
		cin >> value;
		while(value >= 0) {
			numbers.push_back(value);
			cout << "Enter a positive number(negative number to quit): ";
			cin >> value;
		}

	selectionSort(numbers);
	
	int searchFor = 0, index;
	cout << "Enter number to search for (negative to quit): ";
	cin >> searchFor;
	while(searchFor >= 0) 
	{
		index = binarySearch(numbers, searchFor);
		if (index >= 0)
			cout << "Position in sorted array: " << index << endl;
		else
			cout << "Element not in array." << endl;
		cout << "Enter number to search for (negative to quit): ";
		cin >> searchFor;
	}

	return 0;
}
