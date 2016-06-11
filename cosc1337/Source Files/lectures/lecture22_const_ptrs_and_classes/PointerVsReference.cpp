#include <iostream>

using namespace std;

int main()
{
    int num1 = 2;
    int num2 = 4;
    int * const intPtr = &num1;
    int & intRef = num1;
    
    *intPtr = num2;
    intRef = num2;
    
    cout << "num1: " << num1 << endl;
    cout << "intRef: " << intRef << endl;
    
    system("PAUSE");
    return 0;
}
