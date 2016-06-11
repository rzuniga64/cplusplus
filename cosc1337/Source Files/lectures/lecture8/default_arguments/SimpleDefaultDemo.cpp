// SimpleDefaultDemo.cpp
// A totally useless, but hopefully illustrative
// demonstration of default arguments.
#include <iostream>

using namespace std;

void func(int n1 = 3, int n2 = 5, int n3 = 7);

int main()
{
    func(4, 8);
    system("PAUSE");
    return 0;
}

void func(int n1, int n2, int n3)
{
    cout << "n1: " << n1 << ", n2: " << n2;
    cout << ", n3: " << n3 << endl;
}
