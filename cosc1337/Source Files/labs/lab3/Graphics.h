#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <iostream>
#if defined (_WIN32)
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif
#include <stdlib.h>

using namespace std;

// set the drawing window dimensions and position on screen
#define WINDOW_HEIGHT    500
#define WINDOW_WIDTH    500
#define WINDOW_X        100
#define WINDOW_Y        150

// set the pre-defined colors
enum ColorName {WHITE, GREY, BLACK, RED, ORANGE, YELLOW, GREEN, FOREST_GREEN, BLUE, 
                MIDNIGHT_BLUE, CYAN, PURPLE, MAGENTA, BROWN, NUM_COLORS};


// initialization routine
void graphicsSetup(int argc, char **argv);
void drawScene(void);
void clearWindow(void);

// set line or fill color
void setColor(ColorName name);

// graphic object primatives
void drawTriangle(int x1, int y1,int x2,int y2,int x3,int y3);
void drawLine(int x1, int y1, int x2, int y2);
void drawBox(int x1, int y1, int x2, int y2); // x-y coords of upper-right and lower-left corners
void drawCircle(int x, int y, int radius);
void drawOval(int x, int y, int width, int height, int rotateAngle); // angle is in degrees
void drawArc(int x, int y, int radius, int startAngle, int endAngle); // angles are in degrees from straight right

// filled graphics primatives
void drawFilledTriangle(int x1, int y1,int x2,int y2,int x3,int y3);
void drawFilledBox(int x1, int y1, int x2, int y2);
void drawFilledCircle(int x, int y, int radius);
void drawFilledOval(int x, int y, int width, int height, int rotateAngle);  // angle is in degrees

#endif
