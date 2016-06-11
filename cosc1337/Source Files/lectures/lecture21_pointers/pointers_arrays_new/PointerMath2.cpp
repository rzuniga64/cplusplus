#include <iostream>

using namespace std;

int main() {
    const int SIZE = 5;
    short numbers[SIZE] = {10, 20, 30, 40, 50};
    short * ptr = numbers;
    
    // can use i as offset
    for (int i=0; i<SIZE; i++)
        cout << *(ptr+i) << " ";
    cout << endl;
    
    // or, can just increment pointer variable itself
    for (int i=0; i<SIZE; ptr++, i++)
        cout << *ptr << " ";
    cout << endl;
    // reset ptr
    ptr = numbers;
   
    // can't increment array variable, though
    /*
    for (int i=0; i<SIZE; numbers++, i++)
        cout << *numbers << endl;
    cout << endl;
    */
    system("PAUSE");
    return 0;
}
