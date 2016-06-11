 // This program stores employee hours worked and hourly pay rates
 // in vectors.
 #include <iostream>
 #include <iomanip>
 #include <vector> // Needed to use vectors
 using namespace std;

 int main()
 {
	 const int NUM_EMPS = 5; // Number of employees
	 vector <int> hours(NUM_EMPS); // Define a vector of integers
	 vector <double> payRate(NUM_EMPS); // Define a vector of doubles
	 double grossPay;
	 int index; // Loop counter

	 // Get employee work data
	 cout << "Enter the hours worked and hourly pay rates of "
	 << NUM_EMPS << " employees. \n";

	 for (index = 0; index < NUM_EMPS; index++)
	 {
		 cout << "Hours worked by employee #" << (index + 1) << ": ";
		 cin >> hours[index];
		 cout << "Hourly pay rate for employee #" << (index + 1) << ": ";
		 cin >> payRate[index];
	 }
	 // Display each employee’s gross pay
	 cout << "\nHere is the gross pay for each employee:\n";
	 cout << fixed << showpoint << setprecision(2);
	 for (index = 0; index < NUM_EMPS; index++)
	 {
		 grossPay = hours[index] * payRate[index];
		 cout << "Employee #" << (index + 1);
		 cout << ": $" << setw(7) << grossPay << endl;
	 }
	 return 0;
 }
