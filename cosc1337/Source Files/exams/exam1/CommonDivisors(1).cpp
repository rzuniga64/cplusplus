#include <iostream>

using namespace std;

/* greatestCommonDivisor
   input: two integers
   output: the largest integer that divides evenly into both inputs
*/
int greatestCommonDivisor(int a, int b);

int main()
{
	int num1;
	int num2;
	int gcd = 0;

	cout << "Please enter the first number (0 to quit): ";
	cin >> num1;
	while (num1 != 0)
	{
		cout << "Please enter the second number: ";
		cin >> num2;
		gcd = greatestCommonDivisor(num1, num2);
		cout << "The greatest common divisor of " << num1 << " and " << num2 << " is " << gcd << endl;

		cout << "Please enter the first number(0 to quit): ";
		cin >> num1;
	}
	return 0;
}

int greatestCommonDivisor(int a, int b)
{
	a = (a < 0 ? -a : a);
	b = (b < 0 ? -b : b);
	int t;
	while(b != 0)
	{
		t = b;
		b = a % t;
		a = t;
	}
	return a;
}
