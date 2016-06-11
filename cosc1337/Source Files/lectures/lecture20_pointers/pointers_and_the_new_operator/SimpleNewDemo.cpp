// SimpleNewDemo.cpp
#include <iostream>

using namespace std;

int main()
{
    int n = 8;
    int * ptr = new int;
    *ptr = n;
    // make a new ptr to store the address of the dynamically-allocated integer
    int * delPtr = ptr;
    ptr = &n;
    
    cout << "ptr: " << ptr << endl;
    cout << "ptr points to: " << *ptr << endl;
    cout << "n: " << n << endl;
    
    delete delPtr;
    // all the rest of this code is a bad idea
    /*
    cout << ptr << endl;
    cout << *ptr << endl;
    *ptr = 14;
    cout << *ptr << endl;
    */
    
    system("PAUSE");
    return 0;
}
