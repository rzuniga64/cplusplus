 // This program uses an array to store the hours worked by
 // a set of employees who all make the same hourly wage.
 #include <iostream>
 #include <iomanip>
 using namespace std;

 int main()
 {
	 const int NUM_WORKERS = 5; // Set the number of employees
	 int hours[NUM_WORKERS]; // Array to hold each employee's hours
	 double payRate; // Hourly pay rate for all employees

	 // Input hours worked by each employee
	 cout << "Enter the hours worked by \n";
	 for (int worker = 0; worker < NUM_WORKERS; worker++)
	 {
		 cout << "Employee #" << (worker+1) << ": ";
		 cin >> hours[worker];
	 }

	 // Input the hourly pay rate for all employees
	 cout << "\nEnter the hourly pay rate for all the employees: ";
	 cin >> payRate;

	 // Display each employee's gross pay
	 cout << "\nHere is the gross pay for each employee:\n";
	 cout << fixed << showpoint << setprecision(2);
	 for (int worker = 0; worker < NUM_WORKERS; worker++)
	 {
		 double grossPay = hours[worker] * payRate;
		 cout << "Employee #" << (worker + 1);
		 cout << ": $" << setw(7) << grossPay << endl;
	 }
	 return 0;
 }
