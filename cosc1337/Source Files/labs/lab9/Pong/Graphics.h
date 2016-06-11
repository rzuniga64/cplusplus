#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <iostream>
#if defined (_WIN32) || defined(_linux)
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif
#include <stdlib.h>

using namespace std;

// set the drawing screen dimensions and position
#define WINDOW_HEIGHT    500
#define WINDOW_WIDTH    600
#define WINDOW_X        100
#define WINDOW_Y        150

// set the pre-defined colors
enum ColorName {WHITE, BLACK, RED, BLUE, GREEN, GREY, PURPLE, FOREST_GREEN, MIDNIGHT_BLUE, CYAN, MAGENTA, YELLOW, BROWN, NUM_COLORS};


// initialization routine
void graphicsSetup(int argc, char **argv);
void drawScene(void);
void clearWindow(void);

// set line or fill color
void setColor(ColorName name);

// graphic object primatives
void drawTriangle(int x1, int y1,int x2,int y2,int x3,int y3);
void drawLine(int x1, int y1, int x2, int y2);
void drawBox(int x1, int y1, int x2, int y2);
void drawCircle(int x1, int y1, int radius);

// filled graphics primatives
void drawFilledTriangle(int x1, int y1,int x2,int y2,int x3,int y3);
void drawFilledBox(int x1, int y1, int x2, int y2);
void drawFilledCircle(int x1, int y1, int radius);

void drawEightSegmentDigit(int digit, int midx, int midy, int width=20, int height=40);

class GraphicsTimer {
public:
	GraphicsTimer();
	void start();
	int sinceStart(); // return the ms since start was called
	int deltaT(); // returns the ms since last call to deltaT
private:
	int lastElapsed;
};

#endif
