#include "Shapes.h"

Shape::Shape(int xmax, int ymax) {
    this->xmax = xmax;
    this->ymax = ymax;
}

void Shape::init(int halfHeight, int halfWidth) {
	this->halfHeight = halfHeight;
	this->halfWidth = halfWidth;
    colorName = (ColorName)(rand() % NUM_COLORS);
    xpos = rand() % (xmax-halfWidth*2-2) + halfWidth+1;
    ypos = rand() % (ymax-halfWidth*2-2) + halfWidth+1;
    deltax = ((rand() % 10) + 5)*0.5 * (rand()%2 == 0 ? 1 : -1);
    deltay = ((rand() % 10) + 5)*0.5 * (rand()%2 == 0 ? 1 : -1);
}

void Shape::update() {
    if (xpos <= halfWidth || xpos >= xmax - halfWidth)
        deltax = -deltax;
    if (ypos <= halfHeight || ypos >= ymax - halfHeight)
        deltay = -deltay;
    xpos += deltax;
    ypos += deltay;
}

Circle::Circle(int xmax, int ymax) : Shape(xmax, ymax) {
	int radius = rand()%25+25;
	init(radius, radius);
}

void Circle::draw() {
    setColor(colorName); 
    drawFilledCircle((int)xpos, (int)ypos, halfHeight);
}

Box::Box(int xmax, int ymax) : Shape(xmax, ymax) {
	int halfHeight = rand()%25+25, halfWidth = rand()%25+25;
	init(halfHeight, halfWidth);
}

void Box::draw() {
    setColor(colorName);
    drawFilledBox((int)(xpos - halfWidth), (int)(ypos - halfHeight), 
                  (int)(xpos + halfWidth), (int)(ypos + halfHeight));
}

Triangle::Triangle(int xmax, int ymax) : Shape(xmax, ymax)
{
	int halfHeight = rand()%25+25, halfWidth = rand()%25 + 25;
	init(halfHeight, halfWidth);
}

void Triangle::draw() {
    setColor(colorName);
    drawFilledTriangle((int)(xpos - halfWidth), (int)(ypos - halfHeight), 
                       (int)(xpos + halfWidth), (int)(ypos - halfHeight), 
                       (int)xpos, (int)(ypos + halfHeight));
}
