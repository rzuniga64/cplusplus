#include "ArrayFunctions.h"

void readArray(int * dataArray, int arraySize)
{
	for (int i=0; i<arraySize; i++)
	{
		cout << "Enter data for index " << i << ": ";
		cin >> dataArray[i];
	}
}

void sortArray(int * dataArray, int arraySize)
{
    int startScan, minIndex, minValue;
    for (startScan = 0; startScan < (arraySize - 1); startScan++) 
    {
        minIndex = startScan;
        minValue = dataArray[startScan];
        for (int index = startScan + 1; index < arraySize; index++)
        {
            if (dataArray[index] < minValue)
            {
                minValue = dataArray[index];
                minIndex = index;
            }
        }
        dataArray[minIndex] = dataArray[startScan];
        dataArray[startScan] = minValue;
    }
}

double getPercentile(int * sortedArray, int arraySize, int item)
{
	int idx = 0;
	while(idx < arraySize && sortedArray[idx] < item)
		idx++;
	return (idx * 100.0 / arraySize);
}
