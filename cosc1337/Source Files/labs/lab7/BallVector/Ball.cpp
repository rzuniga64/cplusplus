#include "Ball.h"

Ball::Ball(double edgex, double edgey) {
    double radius = (rand() % 40) + 20;
    ColorName colorName = (ColorName) (rand() % NUM_COLORS);
    init(radius, edgex, edgey, colorName);
}

Ball::Ball(double radius, double edgex, double edgey, ColorName colorName) {
    init(radius, edgex, edgey, colorName);
}

void Ball::init(double radius, double edgex, double edgey, ColorName colorName) {
    this->radius = radius;
    this->edgex = edgex;
    this->edgey = edgey;
    this->colorName = colorName;
    // choose initial position and speed randomly
    this->xpos = (double)(rand() % (int)(edgex - 2*radius) + radius);
    this->ypos = (double)(rand() % (int)(edgey - 2*radius) + radius);
    deltax = ((rand() % 50) + 5)/100.0 * (rand()%2 == 0 ? 1 : -1);
    deltay = ((rand() % 50) + 5)/100.0 * (rand()%2 == 0 ? 1 : -1);
}

void Ball::update(int elapsedMS) {
    if ((ypos > (edgey - radius)) || ypos < radius) {
        deltay = -deltay;
    }
    if ((xpos > (edgex - radius)) || xpos < radius) {
        deltax = - deltax;
    }
    xpos = xpos + deltax * elapsedMS;
    ypos = ypos + deltay * elapsedMS;
}

void Ball::draw() {
    setColor(colorName);
    drawFilledCircle((int)xpos,(int)ypos,(int)radius);
}
