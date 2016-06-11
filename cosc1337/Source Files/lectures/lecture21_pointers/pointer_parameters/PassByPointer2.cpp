#include <iostream>

using namespace std;

bool isPrime(int num, int * largestFactor) 
{
    *largestFactor = -1;
    for (int i=num-1; i>=1 && *largestFactor == -1; i--) 
    {
        if (num%i == 0)
            *largestFactor = i;
    }
    return *largestFactor == 1;
}

int main() 
{
    int n, f;
    cout << "Enter an integer (0 or negative to quit): ";
    cin >> n;
    while(n > 0) 
    {
        if (isPrime(n, &f))
            cout << n << " is prime" << endl;
        else
            cout << n << " is composite and the largest factor is " << f << endl;
        cout << "Enter an integer (0 or negative to quit): ";
        cin >> n;
    }
    system("PAUSE");
    return 0;
}
