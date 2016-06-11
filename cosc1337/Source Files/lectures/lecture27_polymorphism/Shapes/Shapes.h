#include "Graphics.h"
#include <iostream>

class Shape {
public:
    Shape(int xmax, int ymax);
    void update();
    virtual void draw()=0;
protected:
	void init(int halfHeight, int halfWidth);
    double xpos;
    double ypos;
    double deltax;
    double deltay;
    int xmax;
    int ymax;
    int halfHeight;
    int halfWidth;
    ColorName colorName;
};

class Circle : public Shape {
public:
    Circle(int xmax, int ymax);
    void draw();
};

class Box : public Shape {
public:
    Box(int xmax, int ymax);
    void draw();
};

class Triangle : public Shape {
public:
    Triangle(int xmax, int ymax);
    void draw();
};
