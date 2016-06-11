// LinearSearch.cpp
// Uses linear search function to search an array.
// Main function initializes and displays an array
// and then allows user to search for elements.
#include <iostream>

using namespace std;

int linearSearch(double array[], int size, double searchFor, int & numComparisons);

int main() {
    const int SIZE = 64;
    double numbers[SIZE];
    cout << "array: ";
    for (int i=0; i<SIZE; i++) {
        numbers[i] = (rand()%100 + 1) / 10.0;
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    // read in values from user
    // as long as value is positive, search for it in array
    // and report the index (or not found)
    double value;
    int index, numComps, totalNumComps = 0, numSearches = 0;
    
    cout << "Enter a value (negative to quit): ";
    cin >> value;
    while (value >= 0)
    {
        index = linearSearch(numbers, SIZE, value, numComps);
        totalNumComps += numComps;
        numSearches++;
        if (index >= 0)
            cout << "Item found at position " << index << "." <<  endl;
        else
            cout << "Item not found." << endl;
        cout << "Enter a value (negative to quit): ";
        cin >> value;
    }
    cout << "Average number of comparisons: ";
    cout << static_cast<double>(totalNumComps) / numSearches << endl;
    
    system("PAUSE");
    return 0;
}

int linearSearch(double array[], int size, double searchFor, int & numComparisons)
{
    int pos = -1;
    numComparisons = 0;
    for (int i=0; i<size && pos < 0; i++) 
    {
        if (array[i] == searchFor)
            pos = i;
        numComparisons++;
    }
    return pos;
}
