// DynamicArray.cpp
#include <iostream>

using namespace std;

void randomizeArray(int * array, int size, int max);
void printArray(int * array, int size);

int main()
{
    int * intArray = NULL;
    int arraySize;
    
    cout << "Enter the size of the array: ";
    cin >> arraySize;
    
    intArray = new int[arraySize];
    randomizeArray(intArray, arraySize, 100);
    printArray(intArray, arraySize);
    
    delete[] intArray;
    
    system("PAUSE");
    return 0;
}

void randomizeArray(int * array, int size, int max)
{
    
    for (int i=0; i<sizeof(array); i++)
        array[i] = (rand() % max) + 1;
}

void printArray(int * array, int size)
{
    for (int i=0; i<size; i++)
        cout << array[i] << " ";
    cout << endl;
}
