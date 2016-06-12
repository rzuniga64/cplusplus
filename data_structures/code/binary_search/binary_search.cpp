/******************************************************
Find an item in a list, return the index or -1
Works only for SORTED lists
Compare target value to middle element in list.
- if equal, then return index
- if less than middle elem, search in first half
- if greater than middle elem, search in last half

If search list is narrowed down to 0 elements,
return -1. Divide and conquer style algorithm

What is the base case? (two base cases)
-	empty list: result = -1 (not found)
What is the recursive case?
- split list into: middle value, first half, last half
- if target == middle value, then return its index
- if target < middle elem, search in first half
- if target > middle elem, search in last half
Need to add parameters for first and last index of 
the current subpart of the list to search.
*******************************************************/
#include <iostream>

using namespace std;

template <typename T>
int binarySearchRec(T array[], int first, int last, int value) {

	int middle = (first + last)/2;	// index of midpoint of search

	if (first > last)		// base case: check for empty list
		return -1;

	cout << "f: " << first << " last: " << last << " middle: " << middle << endl;

	if (value == array[middle])
		return middle;
	if (value < array[middle])	// if value is in lower half
		return binarySearchRec(array, first, middle-1, value);
	else						// if value is in upper half
		return binarySearchRec(array, middle+1, last,  value);
}

template <typename T>
int binarySearch(T array[], int size, int value) {
	return binarySearchRec(array, 0, size-1, value);
}

// iterative search
template <typename T>
int binarySearchIter(T array[], int size, int value) {
	int first = 0;				// index of first array element
	int last = size-1;			
	int middle; 
	int position = -1;
	bool found = false;

	while (!found && first < last) {
		middle = (first + last)/2;
		cout << "f: " << first << " last: " << last << " middle: " << middle << endl;

		if (value = array[middle]) {
			found = true;
			position = middle;
		} else if (value < array[middle])
			first = middle - 1;
		else
			last = middle + 1;
	}

	return position;
}


int main() {
	const int size = 16;	// size of array

	int values[size] = {1,7,8,14,20,22,42,55,67,78,101,112,122,170,179,190};

	int index = binarySearch<int>(values, size, 42);
	cout << "index: " << index << endl;

	int index2 = binarySearch<int>(values, size, 42);
	cout << "index2: " << index2 << endl;
	return 0;
}