/*
 * Purpose:	To calculate and display the distance a car can
 *  		travel on one tank of gas when driven in town
 *  		and when driven on the highway.
 * Inputs:	None
 * Outputs:	1. One display of the distance the car travels on
 * 			one tank of gas when driven in town.
 * 			2. One display of the distance the car travels on
 * 			one tank of gas when driven on the highway.
 */
#include <iostream>
#include <iomanip>	// Header file need to use setprecision, fixed.

using namespace std;

int main()
{
	const double avePerGallonTown = 21.5;
	const double avePerGallonHwy = 26.8;
	const int gallons = 20;

	double distanceInTown = gallons * avePerGallonTown;
	double distanceOnHwy  = gallons * avePerGallonHwy;

	cout << "Distance car travels in town with a " << gallons << " gallon gas tank is "
		 << setprecision(2) << fixed << distanceInTown << " miles" << endl << endl;
	cout << "Distance car travels on the highway with a " << gallons << " gallon gas tank is "
		 << distanceOnHwy << " miles" << endl;
    system("PAUSE");
	return 0;
}
