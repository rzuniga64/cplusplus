/*
 * Purpose:	To calculate and display the distance a car can
 *  		travel on one tank of gas when driven in town
 *  		and when driven on the highway.
 * Inputs:	1. The size of a car's gas tan in gallons.
 * 			2. The average miles per gallon the car travel's in town.
 * 			3. The average miles per gallon the car travel's on the highway.
 * Outputs:	1. One display of the distance the car travels on
 * 			one tank of gas when driven in town.
 * 			2. One display of the distance the car travels on
 * 			one tank of gas when driven on the highway.
 */

#include <iostream>
#include <iomanip> 	// Header file needed for setprecision, fixed.

using namespace std;

int main()
{
	double avePerGallonTown;
	double avePerGallonHwy;
	int gallons;

	cout << "Enter size of gas tank of car in gallons as a whole number: ";
	cin  >> gallons;
	cout << "Enter average miles per gallon car travels in town: ";
	cin >> avePerGallonTown;
	cout << "Enter average miles per gallon car travels on highway: ";
	cin >> avePerGallonHwy;

	double distanceInTown = gallons * avePerGallonTown;
	double distanceOnHwy  = gallons * avePerGallonHwy;

	cout << endl << "Distance car travels in town with a " << gallons << " gallon gas tank is "
		 << setprecision(2) << fixed << distanceInTown << " miles" << endl;
	cout << "Distance car travels on the highway with a " << gallons << " gallon gas tank is "
		 << distanceOnHwy << " miles" << endl;
    system("PAUSE");
	return 0;
}
