#include "Point.h"
#include <cmath>

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

Point Point::addToOther(Point point) {
	Point p(x + point.x, y + point.y);
	return p;
}

void Point::getLineInfo(Point point, double &slope, double &yIntercept) {
	slope = (y - point.y) / (x - point.x);
	yIntercept = y - slope * x;
}
