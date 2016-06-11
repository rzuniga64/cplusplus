#ifndef BALL_H
#define BALL_H

#include <stdlib.h>
#include "Graphics.h"

class Ball {
public:
    Ball(double radius, double edgex, double edgey, ColorName colorName);
    Ball(double edgex, double edgey);
    void update(int elapsedMS=33);
    void draw();
private:
    void init(double radius, double edgex, double edgey, ColorName colorName);
    double radius;
    double edgex;
    double edgey;
    double xpos;
    double ypos;
    double deltax;
    double deltay;
    ColorName colorName;
};

#endif
