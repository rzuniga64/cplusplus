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