#include "Point.h"

int main()
{
	Point p1(3,4), p2(5,6), p3;

	p3 = p1 + p2;

	cout << "p1: " << p1 << endl;
	cout << "p2: " << p2 << endl;
	cout << "p3: " << p3 << endl;

    return 0;
}
