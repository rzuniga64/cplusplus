// This program is supposed to find the square root of 5 numbers
2 // entered by the user. However, if a negative number is entered
3 // an error message displays and a break statement is used to 
4 // stop the loop early. 
5 #include <iostream>
6 #include <cmath>
7 using namespace std;
8
9 int main()
10 {
11 double number;
12 
13 cout << "Enter 5 positive numbers separated by spaces and \n" 
14 << "I will find their square roots: ";

16 for (int count = 1; count <= 5; count++)
17 {
18 cin >> number;
19 if (number >= 0.0)
20 { cout << "\nThe square root of " << number << " is " 
21 << sqrt(number);
22 }
23 else
24 { cout << "\n\n" << number << " is negative. "
25 << "I cannot find the square root \n"
26 << "of a negative number. The program is terminating.\n";
27 break;
28 } 
29 }
30 return
}