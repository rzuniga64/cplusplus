// SumNumbers.cpp
// Calculates and displays the sum of a specified number of integers.
#include <iostream>

using namespace std;

int main()
{
    int numNumbers = 0;
    int number = 0;
    int sum = 0;
    
    cout << "Enter the number of integers: ";
    cin >> numNumbers;
    for(int counter = 0; counter < numNumbers; counter++)
    {
        cout << "Enter integer number " << counter+1 << ": ";
        cin >> number;
        sum = sum + number;
    }
    cout << "Sum of integers: " << sum << endl;
    
	system("PAUSE");
	return 0;
}
