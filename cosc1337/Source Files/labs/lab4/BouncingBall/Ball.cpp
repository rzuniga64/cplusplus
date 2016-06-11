#include "Ball.h"

Ball::Ball(double xEdge, double yEdge) {
    double radius = (rand() % 40) + 20;
    ColorName colorName = (ColorName) (rand() % NUM_COLORS);
    init(radius, xEdge, yEdge, colorName);
}

Ball::Ball(double radius, double xEdge, double yEdge, ColorName colorName) {
    init(radius, xEdge, yEdge, colorName);
}

void Ball::init(double radius, double xEdge, double yEdge, ColorName colorName) {
    this->radius = radius;
    this->xEdge = xEdge;
    this->yEdge = yEdge;
    this->colorName = colorName;
    // choose initial position and speed randomly
    this->xPos = static_cast<double>(rand() % static_cast<int>(xEdge - 2*radius) + radius);
    this->yPos = static_cast<double>(rand() % static_cast<int>(yEdge - 2*radius) + radius);
    xVelocity = ((rand() % 10) + 5)/100.0 * (rand()%2 == 0 ? 20 : -20);
    yVelocity = ((rand() % 10) + 5)/100.0 * (rand()%2 == 0 ? 15 : -15);
}

void Ball::update() {
    xPos = xPos + xVelocity;
    yPos = yPos + yVelocity;

	// Check if the ball exceeds the edges
	if (xPos > xEdge - radius) {
		xPos = xEdge - radius;
		xVelocity = -xVelocity;
	}
	else if (xPos < radius) {
		xPos = radius;
		xVelocity = -xVelocity;
	}
	if (yPos > yEdge - radius) {
		yPos = yEdge - radius;
		yVelocity = -yVelocity;
	}
	else if (yPos < radius) {
		yPos = radius;
		yVelocity = -yVelocity;
	}
}

void Ball::draw() {
    setColor(colorName);
    drawFilledCircle(static_cast<int>(xPos),
                     static_cast<int>(yPos),
                     static_cast<int>(radius));
}
