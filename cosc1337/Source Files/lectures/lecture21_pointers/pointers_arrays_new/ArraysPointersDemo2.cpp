#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    const int SIZE = 5;
    double numbers[SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double * ptr = numbers;
    
    cout << setw(25) << right << "numbers: " << numbers << endl;
    cout << setw(25) << right << "address of numbers: " << &numbers << endl;
    cout << setw(25) << right << "address of first elt: " << &(numbers[0]) << endl;
    
    cout << setw(25) << right << "ptr: " << ptr << endl;
    cout << setw(25) << right << "address of ptr: " << &ptr << endl;
   
    system("PAUSE");
    return 0;
}
