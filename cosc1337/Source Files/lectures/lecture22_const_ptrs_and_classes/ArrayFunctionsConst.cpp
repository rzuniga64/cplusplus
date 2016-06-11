#include <iostream>

using namespace std;

void randomizeArray(double * numbers, int arraySize) {
    for (int i=0; i<arraySize; i++)
        numbers[i] = static_cast<double>(rand()) / RAND_MAX;
}

void displayArray(const double * numbers, int arraySize) {
    for (int i=0; i<arraySize; i++)
        cout << numbers[i] << " ";
    cout << endl;
}


int main() {
    const int SIZE = 10;
    double data[SIZE] = {0.0};
    
    srand(time(0));
    randomizeArray(data, SIZE);
    displayArray(data, SIZE);
    
    system("PAUSE");
    return 0; 
}
