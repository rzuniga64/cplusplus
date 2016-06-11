#include <iostream>

using namespace std;

int main()
{
    const int SIZE = 5;
    const int A[SIZE] = {1, 2, 3, 4, 5};
    
    //A[0] = 17;
    
    // declare and initialize a pointer variable
    // that points to A
    const int * p = A;
        
    system("PAUSE");
    return 0;
}
