#include "Line.h"

//default constructor
Point::Point():itsX(0),itsY(0){}

void Point::setX(int x)
{
	itsX = x;
}

void Point::setY(int y)
{
	itsY = y;
}

int Point::getX() const
{
	return itsX;
}

int Point::getY() const
{
	return itsY;
}

Line::Line(int leftX, int leftY, int rightX, int rightY)
{
	itsLeftPoint.setX(leftX);
	itsLeftPoint.setY(leftY);
	itsRightPoint.setX(rightX);
	itsRightPoint.setY(rightY);
}

Point Line::GetLeftPoint() const
{
	return itsLeftPoint;
}

Point Line::GetRightPoint() const
{
	return itsRightPoint;
}

void Line::SetLeftPoint(Point Location)
{
	itsLeftPoint = Location;
}

void Line::SetRightPoint(Point Location)
{
	itsRightPoint = Location;
}



