// This program writes data to a file.
2 #include <iostream>
3 #include <fstream> // Needed to use files
4 using namespace std;
5
6 int main()
7 {
8 ofstream outputFile;
9
10 // Open the output file 
11 outputFile.open("demofile.txt");
12
13 cout << "Now writing data to the file.\n";
14
15 // Write four names to the file
16 outputFile << "Bach\n";
17 outputFile << "Beethoven\n";
18 outputFile << "Mozart\n";
19 outputFile << "Schubert\n";
20
21 // Close the file
22 outputFile.close();
23
24 cout << "Done.\n";
25 return 0;
26 }

. 