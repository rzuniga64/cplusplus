#include <iostream>

using namespace std;

void selectionSort(int array[], int size);
void displayArray(int array[], int size);

int main() 
{
    const int SIZE = 50;
    int numbers[SIZE];
    for (int i=0; i<SIZE; i++)
        numbers[i] = rand()%100 + 1;
        
    cout << "Array before: ";
    displayArray(numbers, SIZE);

    sort(numbers, SIZE);
    
    cout << "Array after: ";
    displayArray(numbers, SIZE);
        
    system("PAUSE");
    return 0;
}

void sort(int a[], int size)
{
    int start, minIdx, minValue;
    // for each position in the array, except the last one
    for (start = 0; start < (size - 1); start++) 
    {
        // finds the index of the smallest element after a[start]
        minIdx = start;
        for (int i = start + 1; i < size; i++)
        {
            if (a[i] < a[minIdx])
                minIdx = i;
        }
        // swaps a[start] and a[minIdx]
        minValue = a[minIdx];
        a[minIdx] = a[start];
        a[start] = minValue;
    }
}

void displayArray(int array[], int size) {
    for (int i=0; i<size; i++)
        cout << array[i] << " ";
    cout << endl;
}
