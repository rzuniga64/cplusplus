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
 * Input: 	None
 * Output:	Display a bill to console output and a file called bill.txt  that
 * 			includes the input information and the total amount due. If the
 * 			user enters invalid data or the number of hours exceeds 744 then
 * 			the program will print out an informative error message.
 */

using namespace std;

#include <iostream>
#include <iomanip>	// Needed to use setfill, setwidth
#include <fstream>	// need to use ifsteam, ofstream
int main()
{
	ifstream infile;
	ofstream outfile;
	infile.open("rates.txt", ios::in);
	outfile.open("bill.txt", ios::out);

	double packageACost, packageBCost, packageCCost;
	int packageACostPerHour, packageBCostPerHour;
	int packageAHourLimit, packageBHourLimit;

	// read input file to initialize the package variables
	infile >> packageACost >> packageAHourLimit >> packageACostPerHour;
	infile >> packageBCost >> packageBHourLimit >> packageBCostPerHour;
	infile >> packageCCost;

	string name = " ";
	char packageType = ' ';
	int hoursUsed = 0;
	double totalDue = 0.0;

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
			if (hoursUsed > packageAHourLimit)
				totalDue = packageACost + (hoursUsed - packageAHourLimit) * packageACostPerHour;
			else
				totalDue = packageACost;
			break;
		case 'B':
			cout << "Enter number of hours used: ";
			cin  >> hoursUsed;

			// calculate total due if package B
			if (hoursUsed > packageBHourLimit)
				totalDue = packageBCost + (hoursUsed - packageBHourLimit) * packageBCostPerHour;
			else
				totalDue = packageBCost;
			break;
		case 'C':
			// calculate total due if package C
			totalDue = packageCCost;
			break;
		default:
			// An invalid package type was entered.
			cout << endl << "An invalid package type was entered. Run the program\n"
				 << "again and enter a value greater than zero." << endl;
			outfile << endl << "An invalid package type was entered. Run the program\n"
				 << "again and enter a value greater than zero." << endl;
	}

	if (hoursUsed <= 744 )
	{
		// Display a bill that includes the input information and the total amount due.
		cout << endl << left << setw(14) << "Name: " << name << endl;
		cout << setw(14) << "Package type: " << packageType << endl;
		if (packageType =='A' || packageType == 'a' || packageType == 'B' || packageType == 'b')
			cout << setw(14) << "Hours used: " << hoursUsed << endl;
		cout << setw(14) << "Total due: " << totalDue << endl;

		outfile << endl << left << setw(14) << "Name: " << name << endl;
		outfile << setw(14) << "Package type: " << packageType << endl;
		if (packageType =='A' || packageType == 'a' || packageType == 'B' || packageType == 'b')
			outfile << setw(14) << "Hours used: " << hoursUsed << endl;
		outfile << setw(14) << "Total due: " << totalDue << endl;
	}
	else
	{
		// An invalid number of hours used was entered.
		cout << endl << "An invalid number of hours used was entered. Run the program\n"
			 << "again and enter a value less than or equal to 744." << endl;
		outfile << endl << "An invalid number of hours used was entered. Run the program\n"
			 << "again and enter a value less than or equal to 744." << endl;
	}

	infile.close();
	outfile.close();
	return 0;
}
