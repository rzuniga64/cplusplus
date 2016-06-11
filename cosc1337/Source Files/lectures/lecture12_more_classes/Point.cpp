#include "Point.h"

Point::Point() {
	x = 0;
	y = 0;
}

Point::Point(double pointX, double pointY) {
	x = pointX;
	y = pointY;
}

void Point::display() {
	cout << "<" << x << ", " << y << ">" << endl;
}

void Point::readFromUser() {
    char bracket, comma;
    cin >> bracket >> x >> comma >> y >> bracket;
}

double Point::distanceToOther(Point other) {
	return sqrt(pow(x-other.x, 2)+pow(y-other.y, 2));
}