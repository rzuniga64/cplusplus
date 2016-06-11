#include "Graphics.h"
#include <iostream>

class Shape {
public:
    Shape(int xmax, int ymax, int halfHeight);
    Shape(int xmax, int ymax, int halfHeight, int halfWidth);
    void draw() {};
    void update();
protected:
    void randomize();
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
private:
    int radius;
};

class Box : public Shape {
public:
    Box(int xmax, int ymax);
    void draw();
private:
    int height;
    int width;
};

class Triangle : public Shape {
public:
    Triangle(int xmax, int ymax);
    void draw();
private:
    int height;
    int base;
};
