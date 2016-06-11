 // This program reads employee work hours from a file
 // and stores them in an int array. It uses one loop
 // to input the hours and another to display them.
 #include <iostream>
 #include <fstream>
 using namespace std;

 int main()
 {
	 const int NUM_EMPLOYEES = 6; // Sets number of employees
	 int hours[NUM_EMPLOYEES]; // Holds each employee's hours
	 int count = 0; // Loop control variable counts
	 // how many data items have been read in
	 ifstream datafile; // Input file stream object

	 // Open the data file.
	 datafile.open("work.dat");
	 if (!datafile)
		 cout << "Error opening data file\n";
	 else
	 {
		 // Read the numbers from the file into the array. When we exit
		 // the loop, count will hold the number of items read in.
		 while (count < NUM_EMPLOYEES && datafile >> hours[count] )
		 count++;

		 // Close the file.
		 datafile.close();

		 // Display the contents of the array.
		 cout << "The hours worked by each employee are\n";
		 for (int employee = 0; employee < count; employee++)
		 {
			 cout << "Employee " << employee+1 << ": ";
			 cout << hours[employee] << endl;
		 }
	 }
	 return 0;
 }
