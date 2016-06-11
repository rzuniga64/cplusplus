#include <iostream>

using namespace std;

class Point {
	friend Point operator+(const Point & p1, const Point & p2);
	friend ostream & operator<<(ostream & out, const Point & p1);
    public:
		Point();
        Point(double pointX, double pointY);
        void display(ostream & out=cout) const;
        double distanceToOther(const Point & otherPoint) const;
		//Point operator+(const Point & other) const;
    private:
        double x;
        double y;
};

//ostream & operator<<(ostream & out, const Point & p1);