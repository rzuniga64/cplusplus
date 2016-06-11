#include "Polynomial.h"
#include <cmath>

using namespace std;

Polynomial::Polynomial(double aParam, double bParam, double cParam)
{
	a = aParam;
	b = bParam;
	c = cParam;
}

void Polynomial::display() {
	if (a != 0.0)
		cout << a <<"x^2";
	if (a != 0.0 && b> 0.0)
		cout << " + " << b << "x";
	else if (a != 0.0 && b < 0)
		cout << " - " << -b << "x";
	else if (b != 0.0)
		cout << b << "x";
	if ((a != 0.0 || b != 0.0) && c > 0)
		cout << " + " << c;
	else if ((a != 0.0 || b != 0.0) && c < 0)
		cout << " - " << -c;

	cout << endl;
}

double Polynomial::evaluate(double x) {
	return a*pow(x,2) + b*x +c;
}

