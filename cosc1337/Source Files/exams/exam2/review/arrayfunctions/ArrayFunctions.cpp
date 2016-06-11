#include<iostream>
#include <cstdlib>

using namespace std;

void displayArray(const int a[], int size);

// calcAverage prototype
double calcAverage(const int a[], int size);

// findMin prototype
int findMin(const int a[], int size);

// randomizeArray prototype
void randomizeArray(int a[], int size);

bool isPerfect(int number, int &sum);
int sumPerfect(int number);

double clip(double val, double min, double max);

int main() {
    const int NUM_NUMBERS = 10;
    int numbers[NUM_NUMBERS] = {0};
    
    randomizeArray(numbers, NUM_NUMBERS);
        
//    cout << "numbers: ";
//    displayArray(numbers, NUM_NUMBERS);
        
//    cout << "Average of element: " << calcAverage(numbers, NUM_NUMBERS) << endl;
//    cout << "Smallest element: " << findMin(numbers, NUM_NUMBERS) << endl;

    int perfect = sumPerfect(100);

    int array[5] = {56, 78, 59, 45, 12};
    for (int i = 0; i < 5; i++) {
    	int temp = clip (array[i], 60, 75);
    	if ( temp != array[i])
    		array[i] = temp;
    }

    cout << "Hello World";
}

void randomizeArray(int a[], int size) {
    for (int i=0; i<size; i++)
        a[i] = rand()%100 + 1;
}

void displayArray(const int a[], int size) {
    for (int i=0; i<size; i++)
        cout << a[i] << " ";
    cout << endl;
}

double calcAverage(const int a[], int size) {
    double sum = 0.0;
    for (int i=0; i<size; i++)
        sum += a[i];
    return sum / size;
}

int findMin(const int a[], int size) {
    int min = a[0];
    for (int i=0; i<size; i++) {
        if (a[i] < min)
            min = a[i];
    }
    return min;
}

bool isPerfect(int number, int &sum) {
	for (int i=1; i< number; i++)
	{
		bool isPerfect = false;
		if (number % i == 0)
			sum += number;

		if (sum == number)
			isPerfect = true;
		else
			isPerfect = false;
		return isPerfect;
	}
}

int sumPerfect(int number) {
	int sum = 0;
	if (isPerfect(number, sum))
		return sum;
	else
		return false;
}

double clip(double val, double min, double max) {
	int temp =  (val < min ? min : (val > max ? max : val));
    return temp;
}
