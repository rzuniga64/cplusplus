#include "Line.h"

using namespace std;

int main() {

	volatile int leftx, lefty, rightx, righty;

	//the Point class is used as a data member of the Line class that will
	//set the left point and right point for the line.

	Line aLine(0,1,4,5);

	//Get the x and y values of the left and right point.

	leftx  = aLine.GetLeftPoint().getX();
	lefty  = aLine.GetLeftPoint().getY();
	rightx = aLine.GetRightPoint().getX();
	righty = aLine.GetRightPoint().getY();

	return 0;
}



