// This program reads data from a file.
2 #include <iostream>
3 #include <fstream> // Needed to use files
4 #include <string>
5 using namespace std;
6
7 int main()
8 {
9 ifstream inputFile;
10 string name;
11
12 // Open the input file
13 inputFile.open("Friends.txt");
14
15 cout << "Reading data from the file.\n";
16
17 inputFile >> name; // Read name 1 from the file and display it
18 cout << name << endl;
19
20 inputFile >> name; // Read name 2 from the file and display it
21 cout << name << endl;
22
23 inputFile >> name; // Read name 3 from the file and display it
24 cout << name << endl;
25
26 inputFile.close(); // Close the file
27 return 0;
28 }
