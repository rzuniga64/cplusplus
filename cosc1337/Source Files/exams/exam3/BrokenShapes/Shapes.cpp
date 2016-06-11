#include "Shapes.h"

Shape::Shape(int xmax, int ymax, int halfHeight) {
    this->xmax = xmax;
    this->ymax = ymax;
    this->halfHeight = halfWidth = halfHeight;
    randomize();
}

Shape::Shape(int xmax, int ymax, int halfHeight, int halfWidth) {
    this->xmax = xmax;
    this->ymax = ymax;
    this->halfHeight = halfHeight;
    this->halfWidth = halfWidth;
    randomize();
}

void Shape::randomize() {
    colorName = (ColorName)(rand() % NUM_COLORS);
    xpos = rand() % (xmax-halfWidth*2-2) + halfWidth+1;
    ypos = rand() % (ymax-halfWidth*2-2) + halfWidth+1;
    deltax = ((rand() % 10) + 5)/100.0 * (rand()%2 == 0 ? 1 : -1);
    deltay = ((rand() % 10) + 5)/100.0 * (rand()%2 == 0 ? 1 : -1);
}

void Shape::update() {
    if (xpos <= halfWidth || xpos >= xmax - halfWidth)
        deltax = -deltax;
    if (ypos <= halfHeight || ypos >= ymax - halfHeight)
        deltay = -deltay;
    xpos += deltax;
    ypos += deltay;
}

Circle::Circle(int xmax, int ymax) : Shape(xmax, ymax, rand()%25+25) {
}

void Circle::draw() {
    setColor(colorName); 
    drawFilledCircle((int)xpos, (int)ypos, halfHeight);
}

Box::Box(int xmax, int ymax) : Shape(xmax, ymax, rand()%25+25, rand()%25+25) {
}

void Box::draw() {
    setColor(colorName);
    drawFilledBox((int)(xpos - halfWidth), (int)(ypos - halfHeight), 
                  (int)(xpos + halfWidth), (int)(ypos + halfHeight));
}

Triangle::Triangle(int xmax, int ymax) : Shape(xmax, ymax, rand()%25+25, rand()%25+25)
{
}

void Triangle::draw() {
    setColor(colorName);
    drawFilledTriangle((int)(xpos - halfWidth), (int)(ypos - halfHeight), 
                       (int)(xpos + halfWidth), (int)(ypos - halfHeight), 
                       (int)xpos, (int)(ypos + halfHeight));
}
