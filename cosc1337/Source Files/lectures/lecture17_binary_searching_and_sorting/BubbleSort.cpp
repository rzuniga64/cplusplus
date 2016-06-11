#include <iostream>

using namespace std;

void bubbleSort(int array[], int size);
void displayArray(int array[], int size);

int main() 
{
    const int SIZE = 50;
    int numbers[SIZE];
    for (int i=0; i<SIZE; i++)
        numbers[i] = rand()%100 + 1;
        
    cout << "Array before: ";
    displayArray(numbers, SIZE);

    bubbleSort(numbers, SIZE);
    
    cout << "Array after: ";
    displayArray(numbers, SIZE);
        
    system("PAUSE");
    return 0;
}

void bubbleSort(int a[], int size)
{
    int temp, swapIdx, lastSwapIdx = size-1;
    bool swapped = true;
    // while we are still finding swaps necessary
    while (swapped) {
        swapped = false;
        // do a pass of bubble sort (swapping adjacent elts in wrong order)
        for (int i=0; i<lastSwapIdx; i++) {
            if (a[i] > a[i+1]) {
                swapped = true;
                swapIdx = i;
                temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
            }
        }
        lastSwapIdx = swapIdx;
    }
}

void displayArray(int array[], int size) {
    for (int i=0; i<size; i++)
        cout << array[i] << " ";
    cout << endl;
}
