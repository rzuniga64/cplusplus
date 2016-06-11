#include "Point.h"

Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
}

void Point::display() const
{
	cout << "<" << this->x << ", " << this->y << ">" << endl;
}

double Point::distanceToOther(const Point & otherPoint) const
{
	// these lines won't compile because they violate const
	// otherPoint.x = 0;
	// this->x = 0;
    double xDist = this->x - otherPoint.x;
	double yDist = this->y - otherPoint.y;
	return sqrt(xDist*xDist + yDist*yDist);
}
