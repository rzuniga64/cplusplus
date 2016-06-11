#include<iostream>

using namespace std;

void displayArray(const int a[], int size);

// calcAverage prototype
double calcAverage(const int a[], int size);

// findMin prototype
int findMin(const int a[], int size);

// randomizeArray prototype
void randomizeArray(int a[], int size);

int main() {
    const int NUM_NUMBERS = 10;
    int numbers[NUM_NUMBERS] = {0};
    
    randomizeArray(numbers, NUM_NUMBERS);
        
    cout << "numbers: ";
    displayArray(numbers, NUM_NUMBERS);
        
    cout << "Average of element: " << calcAverage(numbers, NUM_NUMBERS) << endl;
    cout << "Smallest element: " << findMin(numbers, NUM_NUMBERS) << endl;
    
    system("PAUSE");
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
