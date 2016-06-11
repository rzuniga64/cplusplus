#ifndef POINT_H
#define POINT_H

#include <iostream>

using namespace std;

class Point {
public:
	Point();
	Point(double pointX, double pointY);
	void display();
	void readFromUser();
	double distanceToOther(Point other);
private:
	double x;
	double y;
};

#endif 