#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    const int SIZE = 5;
    double numbers[SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5};
    
    double * ptr = numbers;
    
    for (int i=0; i<SIZE; i++) {
        ptr[i] = ptr[i] + 2;
    }
    
    for (int i=0; i<SIZE; i++) {
        cout << ptr[i] << " ";
    }
    cout << endl;
   
    system("PAUSE");
    return 0;
}
