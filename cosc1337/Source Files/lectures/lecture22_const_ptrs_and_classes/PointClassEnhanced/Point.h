#include <iostream>

using namespace std;

class Point {
    public:
        Point(double pointX, double pointY);
        void display() const;
        double distanceToOther(const Point & otherPoint) const;
    private:
        double x;
        double y;
};
