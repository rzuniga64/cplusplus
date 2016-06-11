#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <cmath>

using namespace std;

class Polynomial {
public:
	Polynomial(double polyA, double polyB, double polyC);
	void display();
	double evaluate(double x);
	Polynomial addToOther(Polynomial other);
	int calcRoots(double &x1, double &x2);
	bool isLessThan(Polynomial p2, int x);
private:
	double a, b, c;
};

#endif