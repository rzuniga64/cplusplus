#include "MathTutor.h"
#include <iostream>

using namespace std;

void doMathDrills();

int main() {
	// Example constructor call (you will need to change this)
	// Constructs a MathTutor object that drills the
	// user on addition, subtraction, and multiplication
	// problems with operands between 1 and 10.  Targets
	// 50% correct.


	doMathDrills();
	return 0;
}

void doMathDrills() {

	int drills;
	int count = 0;
	double percent;

	cout << "Enter the number of drills per session: ";
	cin >> drills;
	cout << " Enter the target percent correct (e.g. 0.5): ";
	cin >> percent;

	MathTutor tutor(10, "+-*", percent);

	do {
		for (int count = 1; count <= drills; count++)
			tutor.doDrill();
	} while (!tutor.getDrillResults());
}

