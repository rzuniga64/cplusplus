// This program uses a loop to read in multiple values from a file.
2 #include <iostream>
3 #include <fstream> // Needed to use files
4 using namespace std;
int main()
7 {
8 ifstream inputFile; // File stream object
9 int numberOfDays; // Number of days of sales
10 double sales, // Sales amount for a day
11 totalSales = 0.0; // Accumulator
12
13 // Get the number of days
14 cout << "How many days of sales data are stored in your file? ";
15 cin >> numberOfDays;
16
17 // Open the input file
18 inputFile.open("Sales.txt");
19
20 // Loop once for each piece of data to be read from the file
21 for (int count = 1; count <= numberOfDays; count++)
22 {
23 // Read a sales figure from the file and add it to the sum
24 inputFile >> sales;
25 totalSales += sales;
26 }
27 // Close the file
28 inputFile.close();
29
30 cout << "Total sales for the " << numberOfDays << " days were $"
31 << totalSales;
32
33 return
