#include "Point.h"

Point::Point(): x(0), y(0)
{
}

Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
}

void Point::display(ostream & out) const
{
	out << "<" << this->x << ", " << this->y << ">";
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

/*
Point Point::operator+(const Point & other) const 
{
	Point sum(this->x+other.x, this->y+other.y);
	return sum;
}
*/

Point operator+(const Point & p1, const Point & p2) {
   Point sum(p1.x+p2.x, p1.y+p2.y);
   return sum;
}

/*
ostream & operator<<(ostream & out, const Point & p1) {
	p1.display(out);
	return out;
}
*/

ostream & operator<<(ostream & out, const Point & p1) {
	out << "<" << p1.x << ", " << p1.y << ">";
	return out;
}