#ifndef BALL_H
#define BALL_H

#include <stdlib.h>
#include "Graphics.h"

class Ball {
public:
    Ball(double radius, double xEdge, double yEdge, ColorName colorName);
    Ball(double xEdge, double yEdge);
    void update();
    void draw();
private:
    void init(double radius, double xEdge, double yEdge, ColorName colorName);
    double radius;
    double xEdge;
    double yEdge;
    double xPos;
    double yPos;
    double xVelocity;
    double yVelocity;
    ColorName colorName;
};

#endif
