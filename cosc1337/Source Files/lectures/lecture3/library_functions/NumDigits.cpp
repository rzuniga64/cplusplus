#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int number;
    cout << "Enter an integer: ";
    cin >> number;

    int numDigits = static_cast<int>(log10(number))+1;
    cout << number << " has " << numDigits << " digits." << endl;
    
    return 0;
}
