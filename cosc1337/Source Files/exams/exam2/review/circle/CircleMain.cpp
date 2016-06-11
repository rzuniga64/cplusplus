#include "Circle.h"
#include <iostream>

/* NOTE: the following are NON-member functions */
void setCircleArea1(Circle c, double area) {
    c.setArea(area);
}
void setCircleArea2(Circle & c, double area) {
	   c.setArea(area);
	}

int main() {

	Circle c1 ("red", 1.0);
	Circle c2("purple", 2.0);
	cout << boolalpha << "mysteryFunction: " << c1.mysteryFunction(c2) << endl;

	Circle c ("red", 1.0);
	cout << "c before: ";
	c.display();

	setCircleArea1(c, 4.0);
	cout << "c after set area one: ";
	c.display();
	setCircleArea2(c, 2.0);
	cout << "c after set area two: ";
	c.display ();


	return 0;
}



