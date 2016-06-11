// This program tests for file open errors.
2 #include <iostream>
3 #include <fstream> // Needed to use files
4 using namespace std;
5
6 int main()
7 {
8 ifstream inputFile;
9 int number;
10
11 // Attempt to open the input file
12 inputFile.open("ListOfNumbers.txt");
13
14 // If the file successfully opened, process it
15 if (inputFile)
16 {
17 // Read the numbers from the file and display them
18 while (inputFile >> number)
19 cout << number << endl;
20
21 // Close the file
22 inputFile.close();
23 }
24 else // The file could not be found and opened
25 {
26 // Display an error message
27 cout << "Error opening the file.\n";
28 }
29 return 0;
30 }
