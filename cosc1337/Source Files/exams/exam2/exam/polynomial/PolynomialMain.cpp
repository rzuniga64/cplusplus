#include "Polynomial.h"

int main()
{
	Polynomial p(3, -4, 1);
	double x1 = -1, x2 = -1;
	int numRoots = 0;

	p.display();

	numRoots = p.calcRoots(x1, x2);

	if ((x1 != -1) && (x2 != -1)) {
		cout << "root x1 is " << x1 << endl;
		cout << "root x2 is " << x2 << endl;
	} else
		cout << "The polynomial has no real roots.";

	Polynomial p2(-1, 10, 10);

	if (p.isLessThan(p2, 4)) {
		p.display();
		cout << " is less than ";
		p2.display();
		cout << endl;
	}

	return 0;
}