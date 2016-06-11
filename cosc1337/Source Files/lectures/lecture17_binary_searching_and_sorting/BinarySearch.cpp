#include <iostream>

using namespace std;

int binarySearch(int array[], int size, int searchFor, int & numComparisons);
void initializeOrderedArray(int array[], int size);
void displayArray(int array[], int size);

int main() {
    const int SIZE = 64;
    int numbers[SIZE];
    initializeOrderedArray(numbers, SIZE);
    displayArray(numbers, SIZE);
    
    int toFind = 0, index = 0;
    int comparisons, totalComparisons = 0, totalSearches = 0;
    cout << "Enter number to find: ";
    cin >> toFind;
    while(toFind > 0)
    {
        index = binarySearch(numbers, SIZE, toFind, comparisons);
        totalComparisons += comparisons;
        totalSearches++;
        if (index >= 0)
            cout << "Index of element: " << index << endl;
        else
            cout << "Element not found." << endl;
        cout << "Enter number to find: ";
        cin >> toFind;
    }
    cout << "Average number of comparisons: ";
    cout << static_cast<double>(totalComparisons) / totalSearches << endl;
    
    system("PAUSE");
    return 0;
}

int binarySearch(int array[], int size, int searchFor, int & numComparisons)
{
    int firstIdx = 0,
        lastIdx = size-1,
        middleIdx,
        position = -1;
    while(position < 0 && firstIdx <= lastIdx) 
    {
        middleIdx = (firstIdx + lastIdx) / 2;
        if (array[middleIdx] == searchFor)
            position = middleIdx;
        else if (array[middleIdx] > searchFor)
            lastIdx = middleIdx - 1;
        else
            firstIdx = middleIdx + 1;
    }
    return position;
}

void initializeOrderedArray(int array[], int size)
{
    int val = rand()%5;
    for (int i=0; i<size; i++) {
        array[i] = val;
        val += ((rand()%3)+1);
    }
}

void displayArray(int array[], int size)
{
    for (int i=0; i<size; i++)
        cout << array[i] << " ";
    cout << endl;
}
