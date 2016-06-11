/*
 * Purpose: A software company gives discounts to customers that buy large
 * 			quantities of their product, according to the table below. The
 * 			program reads in the number of units purchases and displays the
 * 			relevant discount rate.  If the number is invalid, the program
 * 			will display an error message and not display a discount rate.
 * Input:	The number of units purchased.
 * Output:	The discount rate or error message.
 * 			-----------------------
 * 			Quantity	Discount
 * 			-----------------------
 * 			1-9			no discount
 * 			10-19		20%
 * 			20-49		30%
 * 			50-99		40%
 * 			100 or more	50%
 * 			-----------------------
 */

#include <iostream>
#include <iomanip>	// Needed to use setfill, setwidth

using namespace std;

int main()
{
	int unitsPurchased = 0;
	int discountRate = 0;

	cout << "Enter the number of units to purchase: ";
	cin >> unitsPurchased;

	if (unitsPurchased >= 0)
	{
		if (unitsPurchased >= 1 && unitsPurchased <= 9)
			discountRate = 0;
		else if (unitsPurchased >= 10 && unitsPurchased <= 19)
			discountRate = 20;
		else if (unitsPurchased >= 20 && unitsPurchased <= 49)
			discountRate = 30;
		else if (unitsPurchased >= 50 && unitsPurchased <= 99)
			discountRate = 40;
		else if (unitsPurchased >= 100)
			discountRate = 50;

		cout << "The discount rate for a quantity of " << unitsPurchased << " units is " << discountRate << "%" << endl;
	}
	else
	{
		// An invalid number of units purchased was entered.
		cout << endl << "An invalid number was entered. Run the program\n"
			 << "again and enter a value equal to or greater than zero" << endl;
	}

		return 0;
}
