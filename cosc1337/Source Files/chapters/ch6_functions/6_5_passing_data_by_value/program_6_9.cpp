1 // This program demonstrates that changes to a function
2 // parameter have no effect on the original argument.
3 #include <iostream>
4 using namespace std;
5
6 // Function Prototype
7 void changeMe(int aValue);
8
9 int main()
10 {
11 int number = 12;
12
13 // Display the value in number
14 cout << "In main number is " << number << endl;
15
16 // Call changeMe, passing the value in number as an argument
17 changeMe(number);
18
19 // Display the value in number again
20 cout << "Back in main again, number is still " << number << endl;
21 return 0;
22 }
23
24 /*************************************
25 * changeMe *
26 * This function changes the value *
27 * stored in its parameter myValue *
28 *************************************/
29 void changeMe(int myValue)
30 {
31 // Change the value of myValue to 0
32 myValue = 0;
33
34 // Display the value in myValue
35 cout << "In changeMe, the value has been changed to "
36 << myValue << endl;
37 }
