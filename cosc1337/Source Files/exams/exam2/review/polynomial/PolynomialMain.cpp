#include "Polynomial.h"
#include <iostream>

using namespace std;

int main() {

	Polynomial p[5] = {{0,2,3}, {1,0,3}, {1,2,0}, {-1,-2, -3}, {1,2,3}};

	for (int i=0; i < 5; i++) {
		p[i].display();
		cout << "evaluated at 2: " << p[i].evaluate(2) << endl;
	}

	return 0;
}
