#include <iostream>

using namespace std;

int main() {
    const int SIZE = 5;
    short numbers[SIZE] = {10, 20, 30, 40, 50};
    
    cout << "Element 0 is: ";
    cout << *numbers << endl;
   
    cout << "Element 1 is: ";
    cout << *(numbers+1) << endl;
   
    system("PAUSE");
    return 0;
}
