#include "Circle.h"
#include <cmath>
#include <iostream>

using namespace std;

const double M_PI = acos(-1);

Circle::Circle(string circleColor, double circleRadius) {
    color = circleColor;
    radius = circleRadius;
    area = M_PI * radius * radius;
    circumference = 2 * M_PI * radius;
}
void Circle::display() {
    cout << color << " circle with radius " << radius << endl;
}

bool Circle::mysteryFunction(Circle other) {
    return (area >= other.area * 2);
}
void Circle::setArea(double a) {
    area = a;
    radius =  sqrt(area / M_PI);
    circumference = 2 * M_PI * radius;
}

