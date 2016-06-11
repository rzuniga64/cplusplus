#ifndef CIRCLE_H_
#define CIRCLE_H_

#include <string>

using namespace std;

class Circle {
public:
    Circle(string circleColor, double circleRadius = -1);
    void display();
    bool mysteryFunction(Circle other);
    void setArea(double a);
private:
    string color;
    double radius;
    double area;
    double circumference;
};

#endif /* CIRCLE_H_ */
