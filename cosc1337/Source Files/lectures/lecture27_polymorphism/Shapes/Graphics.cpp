#include "Graphics.h"
#include <cmath>

double PI = acos(-1.0);
double ANGLE_STEP      = PI/180.0;

void setColor(ColorName name) {
    switch(name) {
        case WHITE:
            glColor3d(1.0, 1.0, 1.0);
            break;
        case BLACK:
            glColor3d(0.0, 0.0, 0.0);
            break;
        case RED:
            glColor3d(1.0, 0.0, 0.0);
            break;
        case BLUE:
            glColor3d(0.0, 0.0, 1.0);
            break;
        case GREEN:
            glColor3d(0.0, 1.0, 0.0);
            break;
        case GREY:
            glColor3d(0.4, 0.4, 0.4);
            break;
        case PURPLE:
            glColor3d(0.5, 0.25, 0.0);
            break;
        case FOREST_GREEN:
            glColor3d(0.0, 0.25, 0.0);
            break;
        case MIDNIGHT_BLUE:
            glColor3d(0.0, 0.0, 0.25);
            break;
        case CYAN:
            glColor3d(0.0, 1.0, 1.0);
            break;
        case MAGENTA:
            glColor3d(1.0, 0.0, 1.0);
            break;
        case YELLOW:
            glColor3d(1.0, 0.5, 0.0);
            break;
        case BROWN:
            glColor3d(0.5, 0.25, 1.0);
            break;
    }
}

void graphicsSetup(int argc, char **argv) {
     glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
	 glutInitWindowPosition(WINDOW_X,WINDOW_Y);
	 glutInitWindowSize(WINDOW_WIDTH,WINDOW_HEIGHT);
	 glutCreateWindow("COSC1320 - Shapes");
	 glClearColor(1.0,1.0,1.0,0.0);
     //glClearColor(0.0,0.0,0.0,0.0);
	 gluOrtho2D(0,WINDOW_WIDTH, 0,WINDOW_HEIGHT);
}

void clearWindow() {
     glClear(GL_COLOR_BUFFER_BIT);
}

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
     glBegin(GL_LINE_STRIP);
     glVertex2i(x1,y1);
     glVertex2i(x2,y2);
     glVertex2i(x3,y3);
     glVertex2i(x1,y1);
     glEnd();
}

void drawFilledTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
     glBegin(GL_POLYGON);
     glVertex2i(x1,y1);
     glVertex2i(x2,y2);
     glVertex2i(x3,y3);
     glVertex2i(x1,y1);
     glEnd();
}

void drawLine(int x1, int y1, int x2, int y2) {
     glBegin(GL_LINE_STRIP);
     glVertex2i(x1,y1);
     glVertex2i(x2,y2);
     glEnd();
}

void drawBox(int x1, int y1, int x2, int y2) {
     glBegin(GL_LINE_STRIP);
     glVertex2i(x1,y1);
     glVertex2i(x2,y1);
     glVertex2i(x2,y2);
     glVertex2i(x1,y2);
     glVertex2i(x1,y1);
     glEnd();
}

void drawFilledBox(int x1, int y1, int x2, int y2) {
     glBegin(GL_POLYGON);
     glVertex2i(x1,y1);
     glVertex2i(x2,y1);
     glVertex2i(x2,y2);
     glVertex2i(x1,y2);
     glVertex2i(x1,y1);
     glEnd();
}

void drawCircle(int x1, int y1, int radius) {
     double angle;
     int X, Y;
     glBegin(GL_LINE_STRIP);
     for (angle=0;angle< 2.0*PI + ANGLE_STEP; angle += ANGLE_STEP) {
         X = x1 + int(double(radius) * cos(angle));
         Y = y1 + int(double(radius) * sin(angle));
         glVertex2i(X,Y);
     }
     glEnd();
}         

void drawFilledCircle(int x1, int y1, int radius) {
     double angle;
     int X0, Y0, X1, Y1;
     glBegin(GL_TRIANGLES);
     X1 = x1 + radius;
     Y1 = y1;
     for (angle=0;angle< 2.0*PI + ANGLE_STEP; angle += ANGLE_STEP) {
         X0 = X1;
         Y0 = Y1;
         X1 = x1 + int(double(radius) * cos(angle));
         Y1 = y1 + int(double(radius) * sin(angle));
         glVertex2i(x1,y1);
         glVertex2i(X0,Y0);
         glVertex2i(X1,Y1);
     }
     glEnd();
}         

enum Segment {TOP=1, TOP_LEFT=2, TOP_RIGHT=4, MID=8, BOTTOM_LEFT=16, BOTTOM_RIGHT=32, BOTTOM=64};

const int digitFlags[10] = {TOP | TOP_RIGHT | BOTTOM_RIGHT | BOTTOM | BOTTOM_LEFT | TOP_LEFT, // 0
                            TOP_RIGHT | BOTTOM_RIGHT, // 1
                            TOP | TOP_RIGHT | MID | BOTTOM_LEFT | BOTTOM, // 2
                            TOP | TOP_RIGHT | MID | BOTTOM_RIGHT | BOTTOM, // 3
                            TOP_LEFT | MID |TOP_RIGHT | BOTTOM_RIGHT, // 4
                            TOP | TOP_LEFT | MID | BOTTOM_RIGHT | BOTTOM, // 5
                            TOP | TOP_LEFT | MID | BOTTOM_LEFT | BOTTOM_RIGHT | BOTTOM, // 6
                            TOP | TOP_RIGHT | BOTTOM_RIGHT, // 7
                            TOP | TOP_LEFT | TOP_RIGHT | MID | BOTTOM_LEFT | BOTTOM_RIGHT | BOTTOM, // 8
                            TOP | TOP_LEFT | TOP_RIGHT | MID | BOTTOM_RIGHT | BOTTOM}; // 9
                      

void drawHorizontalSegment(int midx, int midy, int width, int height)
{
    if (width <= 0)
        drawFilledBox(midx-2, midy-height/2, midx+2, midy+width/2);
    else
    {
        drawFilledBox((int)(midx-width*1.5), (int)(midy-height/2), 
                      (int)(midx+width*1.5), (int)(midy+height/2));
        drawFilledTriangle((int)(midx-width*2), midy, (int)(midx-width*1.5), 
                           midy-height/2, (int)(midx-width*1.5), midy+height/2);        
        drawFilledTriangle((int)(midx+width*2), midy, (int)(midx+width*1.5), 
                            midy-height/2, (int)(midx+width*1.5), midy+height/2);
    }
}

void drawVerticalSegment(int midx, int midy, int width, int height)
{
    if (height <= 0)
        drawFilledBox(midx-width/2, midy-2, midx+width/2, midy+2);
    else {
        drawFilledBox(midx-width/2, (int)(midy-height*1.5), midx+width/2, (int)(midy+height*1.5));
        drawFilledTriangle(midx, midy+height*2, midx-width/2, (int)(midy+height*1.5), 
                           midx+width/2, (int)(midy+height*1.5));        
        drawFilledTriangle(midx, midy-height*2, midx-width/2, (int)(midy-height*1.5), 
                           midx+width/2, (int)(midy-height*1.5));        
    }
}

void drawEightSegmentDigit(int digit, int midx, int midy, int width, int height)
{
    if (digit >= 0 && digit <= 9) {
        int flags = digitFlags[digit];
        int segHeight = height / 8;
        int segWidth = width / 4;
        if (flags & TOP)
            drawHorizontalSegment(midx, midy+4*segHeight+2, segWidth, segHeight);
        if (flags & TOP_LEFT)
            drawVerticalSegment(midx-2*segWidth-2, midy+2*segHeight+2, segWidth, segHeight);
        if (flags & TOP_RIGHT)
            drawVerticalSegment(midx+2*segWidth+2, midy+2*segHeight+2, segWidth, segHeight);
        if (flags & MID)
            drawHorizontalSegment(midx, midy, segWidth, segHeight);
        if (flags & BOTTOM_LEFT)
            drawVerticalSegment(midx-2*segWidth-2, midy-2*segHeight-2, segWidth, segHeight);
        if (flags & BOTTOM_RIGHT)
            drawVerticalSegment(midx+2*segWidth+2, midy-2*segHeight-2, segWidth, segHeight);
        if (flags & BOTTOM)
            drawHorizontalSegment(midx, midy-4*segHeight-2, segWidth, segHeight);
    }
}



