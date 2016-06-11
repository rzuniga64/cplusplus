#include "Point.h"

int main() {
	Point p1(1,1), p2(4,5);

	p1.display();
	p2.display();

	cout << "distance from p1 to p2: " << p1.distanceToOther(p2) << endl;
	cout << "distance from p2 to p1: " << p2.distanceToOther(p1) << endl;

//	cout << "Enter a properly formatted point: ";
//	p1.readFromUser();
//	cout << "p1: ";
//	p1.display();

	cout << "addition of points p1 and p2: " << endl;
	Point p3 = p1.addToOther(p2);
	cout << "p1.x + p2.x = ";
	p3.display();

	double m, b;
	p1.getLineInfo(p2, m, b);
	cout << "slope: " << m << ", y intercept: " << b << endl;

    return 0;
}
