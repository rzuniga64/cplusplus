// This program uses a for loop to display the numbers 1-5 
2 // and their squares.
3 #include <iostream>
4 #include <iomanip>
5 using namespace std;
6
7 int main()
8 { int num;
9
10 cout << "Number Square\n";
11 cout << "--------------\n";
12
13 for (num = 1; num <= 5; num++)
14 cout << setw(4) << num << setw(7) << (num * num) << endl;
15 return 0;
16 }
Program
