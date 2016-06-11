#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include <iostream>

using namespace std;

class Polynomial {
public:
	Polynomial(double aParam, double bParam, double cParam);
	void display();
	double evaluate(double x);

private:
	double a, b, c;
};

#endif /* POLYNOMIAL_H_ */
