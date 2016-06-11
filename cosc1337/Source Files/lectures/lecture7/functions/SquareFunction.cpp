#include <iostream>

using namespace std;

double square(double x) 
{
    return x*x;
}

int main()
{
    double d, dSq;
    cout << "Enter a number: ";
    cin >> d;
    
    dSq = square(d);
    cout << d << " squared is " << dSq << endl;
    
    system("PAUSE");
    return 0;
}
