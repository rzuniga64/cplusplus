#include <iostream>

using namespace std;

// This is not right!
void swap1(int * a, int * b)
{
    int * temp = a;
    a = b;
    b = temp;
}

// This is best.
void swap2(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int num1 = 8;
    int num2 = 16;
    
    swap1(&num1, &num2);
    
    cout << "num1: " << num1 << endl;
    cout << "num2: " << num2 << endl;
    
    system("PAUSE");
    return 0;
}
