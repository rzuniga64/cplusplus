// This program uses a loop to write multiple values to a file.
2 #include <iostream>
3 #include <fstream> // Needed to use files
4 using namespace std;
5
6 int main()
7 {
8 ofstream outputFile; // File stream object
9 int numberOfDays; // Number of days of sales
10 double sales; // Sales amount for a day
11
12 // Get the number of days
13 cout << "For how many days do you have sales? ";
14 cin >> numberOfDays;
15
16 // Open the output file
17 outputFile.open("Sales.txt");
18
19 // Loop once for each day of sales
20 for (int count = 1; count <= numberOfDays; count++)
21 {
22 // Get the sales amount for a day
23 cout << "Enter the sales for day " << count << ": ";
24 cin >> sales;
25
26 // Write the sales amount to the file
27 outputFile << sales << endl;
28 }
29 // Close the file
30 outputFile.close();
31
32 cout << "Data written to Sales.txt\n";
33 return 0;
34 }
