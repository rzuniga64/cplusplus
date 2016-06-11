/*
 * Purpose: An Internet service provider has three different subscription
 * 			packages for its customers.
 * 			Package A: For $9.95 per month 10 hours of access are provided.
 * 			Additional hours are $2.00 per hour.
 * 			Package B: For $14.95 per month 20 hours of access are provided.
 * 			Additional hours are $1.00 per hour.
 * 			Package C: For $19.95 per month unlimited access is provided.
 *
 *			This program calculates a customers monthly bill.
 * Input: 	the customer's name and which package the customer has purchased
 *  		(in that order).  It will read in how many hours were used if that
 *  		is relevant to calculating the amount due.
 * Output:	Display a bill to console output that includes the input information
 *  		and the total amount due.  If the user enters invalid data or the
 *  		number of hours exceeds 744 then the program will print out an
 *  		informative error message.
 */

using namespace std;

#include <iostream>
#include <iomanip>	// Needed to use setfill, setwidth

int main()
{
	const double PACKAGE_A_COST = 9.95;
	const double PACKAGE_B_COST = 14.95;
	const double PACKAGE_C_COST = 19.95;
	const double A_COST_PER_HOUR = 2.00;
	const double B_COST_PER_HOUR = 1.00;
	int A_HOUR_LIMIT = 10;
	int B_HOUR_LIMIT = 20;

	string name = " ";			// name of user
	char packageType = ' ';		// type of subscription package
	int hoursUsed = 0;			// total number of hours used for the month
	double totalDue = 0.0;		// total

	cout << "Enter first and last name: ";
	getline(cin, name);
	cout << "What package type (A, B, or C): ";
	cin >> packageType;

	switch(toupper(packageType))
	{
		case 'A':
			cout << "Enter number of hours used: ";
			cin  >> hoursUsed;

			// calculate total due if package A
			if (hoursUsed > A_HOUR_LIMIT)
				totalDue = PACKAGE_A_COST + (hoursUsed - A_HOUR_LIMIT) * A_COST_PER_HOUR;
			else
				totalDue = PACKAGE_A_COST;
			break;
		case 'B':
			cout << "Enter number of hours used: ";
			cin  >> hoursUsed;

			// calculate total due if package A
			if (hoursUsed > B_HOUR_LIMIT)
				totalDue = PACKAGE_B_COST + (hoursUsed - B_HOUR_LIMIT) * B_COST_PER_HOUR;
			else
				// calculate total due if package A
				totalDue = PACKAGE_B_COST;
			break;
		case 'C':
			totalDue = PACKAGE_C_COST;
			break;
		default:
			// An invalid package type was entered.
			cout << endl << "An invalid package type was entered. Run the program\n"
				 << "again and enter a value greater than zero." << endl;
	}

	if (hoursUsed <= 744 )
	{
		// Display a bill that includes the input information and the total amount due.
		cout << endl << left << setw(14) << "Name: " << name << endl;
		cout << "package type is " << packageType << endl;
		cout << setw(14) << "Package type: " << packageType << endl;
		if (packageType =='A' || packageType == 'a' || packageType == 'B' || packageType == 'b')
			cout << setw(14) << "Hours used: " << hoursUsed << endl;
		cout << setw(14) << "Total due: " << totalDue << endl;
	}
	else
		// An invalid number of hours used was entered.
		cout << endl << "An invalid number of hours used was entered. Run the program\n"
			 << "again and enter a value less than or equal to 744." << endl;
	return 0;
}
