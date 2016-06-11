#include "Polynomial.h"
#include <cmath>

Polynomial::Polynomial(double polyA, double polyB, double polyC)
{
	a = polyA;
	b = polyB;
	c = polyC;
}

void Polynomial::display() 
{
	cout << a << "x^2 + ";
	cout << b << "x + ";
	cout << c << endl;
}

double Polynomial::evaluate(double x)
{
	return a*x*x + b*x + c;
}

Polynomial Polynomial::addToOther(Polynomial other)
{
	Polynomial sum(a + other.a, b + other.b, c + other.c);
	return sum;
}

int Polynomial::calcRoots(double &x1, double &x2) {
	int numRoots;

	if (a == 0) {
		numRoots = 1;
		x1 = -(c/b);
		x2 = -(c/b);
	}
	else if (((pow(b,2) -(4 *a*c))) < 0) {
		numRoots = 0;
	}
	else {
		numRoots = 2;

		x1 = (-b + sqrt(pow(b,2) -4 *a*c)) / (2*a);
		x2 = (-b - sqrt(pow(b,2) -4 *a*c)) / (2*a);
	}

	return numRoots;
}

bool Polynomial:: isLessThan(Polynomial p2, int x) {

	return this->evaluate(x) < p2.evaluate(x);
}
