#include <iostream>
#include <cmath>

using namespace std;

void calcFutureValue(double deposit, double apr, int years, double &value);

int main()
{
	double deposit = 0.0;
	double apr = 0.0;
	int years = 0;
	double value = 0.0;

	// Let's do an inital calculation to see if my function is correct.
	deposit = 1000.00;
	apr = 0.05;
	years = 10;
	calcFutureValue(deposit, apr, years, value);
	cout << "Value of account after " << years << " is " << value << endl;

	// Part b.
	deposit = 5000.00;
	value = 0;
	years = 10;
	apr = 0.005;
	while (value < 10000.00)
	{
		calcFutureValue(deposit, apr, years, value);
		apr += 0.005;
	}
		cout << "Value of " << deposit << " after " << years << " at rate " << apr << " is " << value << endl;

	//need this to see console output in VS Studio
	cin.get();
	return 0;
}

void calcFutureValue(double deposit, double apr, int years, double &value)
{
	value = deposit * pow((1.0 + apr),years);
}
