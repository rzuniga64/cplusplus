// PrimeTest.cpp
// Accepts a positive integer from the user and
// determines whether or not the number is prime.
#include <iostream>

using namespace std;

int main()
{
    int num;
    
    cout << "Enter a positive number: ";
    cin >> num;
    
    if (num > 0)
    {   
        int i;
        for (i=2; num%i != 0; i++) {
        }
        cout << num;
        if (i == num)
            cout << " is prime.";
        else
            cout << " is composite.";
        cout << endl;
    }
    else
    {
        cout << "That number was not positive." << endl;
    }
    system("PAUSE");
    return 0;
}
