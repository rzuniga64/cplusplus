1 // This program uses a loop to read in values
2 // from a file until the end of file is reached.
3 #include <iostream>
4 #include <fstream> // Needed to use files
5 using namespace std;
6
7 int main()
8 {
9 ifstream inputFile; // File stream object
10 int numberOfDays = 0; // Counts the records in the file
11 double sales, // Sales amount for a day
12 totalSales = 0.0; // Accumulator
13
14 // Open the input file
15 inputFile.open("Sales.txt");
16
17 // Loop until the EOF is reached
18 while(inputFile >> sales) // If a value was read
19 { totalSales += sales;
20 numberOfDays++;
21 }
22 // Close the file
23 inputFile.close();
24
25 cout << "Total sales for the " << numberOfDays << " days were $"
26 << totalSales;
27
28 return 0;
29 }
