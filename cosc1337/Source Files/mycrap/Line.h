#ifndef LINE_H_
#define LINE_H_

class Point				//holds x,y coordinates
//used to test classes as member data
{
public:
	Point();
	void setX(int x);
	void setY(int y);
	int getX() const;
	int getY() const;
private:
	int itsX;
	int itsY;
};

class Line
{
//class that uses Point class as member data
public:
	Line(int leftX, int leftY, int rightX, int rightY);

	Point GetLeftPoint() const; //{ return itsLeftPoint; }
	Point GetRightPoint() const; //{ return itsRightPoint; }
	void SetLeftPoint(Point Location); //{itsLeftPoint = Location;}
	void SetRightPoint(Point Location); //{itsRightPoint = Location;}
private:
	Point itsLeftPoint;
	Point itsRightPoint;
};


#endif /* LINE_H_ */
