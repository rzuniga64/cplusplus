#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double calcAPRValue(double deposit, double apr, int years, double &value);

int main()
{
	double deposit = 0.0;
	double apr = 0.0;
	int years = 0;
	double value = 0.0;

	deposit = 5000.00;
	value = 10000.0;
	years = 0;
	apr = 0.0;
	for (int years = 2; years <=10; years += 2)
	{	
		apr = calcAPRValue(deposit, apr, years, value); 
		cout << "The rate to get to 10000 in " << years << " years is " << fixed << setprecision(5) << apr << endl;
	}

	//need this to see console output in VS Studio
	cin.get();
	return 0;
}

double calcAPRValue(double deposit, double apr, int years, double &value)
{
	//apr = abs((years * log10(value))/deposit - 1);
	apr = pow(value/deposit, static_cast<double>(1.0/years))-1;

	return apr;
}
