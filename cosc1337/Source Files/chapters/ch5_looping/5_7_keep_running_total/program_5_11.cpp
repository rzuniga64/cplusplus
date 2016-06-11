// This program takes daily sales figures over a period of time
2 // and calculates their total. It then uses this total to compute
3 // the average daily sales.
4 #include <iostream>
5 #include <iomanip>
6 using namespace std;
7
8 int main()
9 {
10 int numDays; // Number of days
11 double dailySales, // The sales amount for a single day
12 totalSales = 0.0, // Accumulator, initialized with 0
13 averageSales; // The average daily sales amount
14
15 // Get the number of days
16 cout << "For how many days do you have sales figures? ";
17 cin >> numDays;
18
19 // Get the sales for each day and accumulate a total 
20 for (int day = 1; day <= numDays; day++) // day is the counter
21 { 
22 cout << "Enter the sales for day " << day << ": ";
23 cin >> dailySales;
24 totalSales += dailySales; // Accumulate the running total
25 }
26 // Compute the average daily sales
27 averageSales = totalSales / numDays;
28 
29 // Display the total sales and average daily sales
30 cout << fixed << showpoint << setprecision(2);
31 cout << "\nTotal sales: $" << setw(8) << totalSales;
32 cout << "\nAverage daily sales: $" << setw(8) << averageSales
33 << endl;
34 return 0;
35 }
 