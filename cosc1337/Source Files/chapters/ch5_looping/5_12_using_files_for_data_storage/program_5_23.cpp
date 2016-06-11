// This program lets the user enter a filename.
2 #include <iostream>
3 #include <string>
4 #include <fstream> // Needed to use files
5 using namespace std;
7 int main()
8 {
9 ifstream inputFile;
10 string filename;
11 int number;
12
13 // Get the filename from the user
14 cout << "Enter the filename: ";
15 cin >> filename;
16
17 // Open the input file
18 inputFile.open(filename.c_str());
19
20 // If the file successfully opened, process it
21 if (inputFile)
22 {
23 // Read the numbers from the file and display them
24 while (inputFile >> number)
25 cout << number << endl;
26
27 // Close the file.
28 inputFile.close();
29 }
30 else
31 {
32 // Display an error message
33 cout << "Error opening the file.\n";
34 }
35 return
