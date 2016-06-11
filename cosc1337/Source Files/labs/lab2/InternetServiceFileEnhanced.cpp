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

	string name = " ";			// name of user
	char packageType = ' ';		// type of subscription package
	int hoursUsed = 0;			// total number of hours used for the month
	int hoursInMonth = 0;		// total number of hours in a month
	double totalDue = 0.0;		// total
	string month;				// the name of the month

	cout << "Enter first and last name: ";
	getline(cin, name);
	cout << "What package type (A, B, or C): ";
	cin >> packageType;

	switch(toupper(packageType))
	{
		case 'A':
			cout << "Enter number of hours used: ";
			cin  >> hoursUsed;
			cin.ignore();
			cout << "Enter the name of the month (i.e. January): ";
			getline(cin, month);

			// calculate total due if package A
			if (hoursUsed > packageAHourLimit)
				totalDue = packageACost + (hoursUsed - packageAHourLimit) * packageACostPerHour;
			else
				totalDue = packageACost;
			break;
		case 'B':
			cout << "Enter number of hours used: ";
			cin  >> hoursUsed;
			cin.ignore();
			cout << "Enter the name of the month (i.e. January): ";
			getline(cin, month);

			// calculate total due if package B
			if (hoursUsed > packageBHourLimit)
				totalDue = packageBCost + (hoursUsed - packageBHourLimit) * packageBCostPerHour;
			else
				totalDue = packageBCost;
			break;
		case 'C':
			// calculate total due if package B
			totalDue = packageCCost;
			break;
		default:
			// An invalid package type was entered.
			cout << endl << "An invalid package type was entered. Run the program\n"
				 << "again and enter a value greater than zero." << endl;
			outfile << endl << "An invalid package type was entered. Run the program\n"
				 << "again and enter a value greater than zero." << endl;
	}

	for (unsigned int i=0; i< month.length(); i++)
		month[i] = toupper(month[i]);

	// get the total number of hours for the month entered
	if (month == "JANUARY" || month == "MARCH" || month == "MAY" || month =="JULY" || month == "AUGUST" || month == "OCTOBER" || month == "DECEMBER")
		hoursInMonth = 744;
	else if (month == "APRIL" || month == "JUNE" || month == "SEPTEMBER" || month == "NOVEMBER")
		hoursInMonth = 720;
	else if (month == "FEBRUARY")
		hoursInMonth = 672;

	if (hoursInMonth != 0 && hoursUsed <= hoursInMonth )
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
	else if (hoursInMonth !=0 && hoursUsed > hoursInMonth)
	{
		// An invalid number of hours used was entered.
		cout << endl << "An invalid number of hours used was entered. Run the program\n"
			 << "again and enter a value less than or equal to " << hoursInMonth << endl;
		outfile << endl << "An invalid number of hours used was entered. Run the program\n"
			 << "again and enter a value less than or equal to " << hoursInMonth << endl;
	}
	else if (hoursInMonth == 0)
	{
		// An invalid month was entered.
		cout << endl << "An invalid month was entered. Run the program\n"
			 << "again and enter a valid month " << endl;
		outfile << endl << "An invalid month was entered. Run the program\n"
			 << "again and enter a valid month " << endl;
	}


	infile.close();
	outfile.close();
	return 0;
}
