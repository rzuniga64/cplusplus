// This program averages test scores. It asks the user for the
2 // number of students and the number of test scores per student.
3 #include <iostream>
4 using namespace std;
5
6 int main()
7 {
8 int numStudents, // Number of students
9 numTests; // Number of tests per student
10 double average; // Average test score for a student
11
12 // Get the number of students
13 cout << "This program averages test scores.\n";
14 cout << "How many students are there? ";
15 cin >> numStudents;
16
17 // Get the number of test scores per student
18 cout << "How many test scores does each student have? ";
19 cin >> numTests;
20 cout << endl;
21
22 // Read each student's scores and compute their average
23 for (int snum = 1; snum <= numStudents; snum++) // Outer loop
24 { double total = 0.0; // Initialize accumulator 
25
26 for (int test = 1; test <= numTests; test++) // Inner loop
27 { int score;
29 // Read a score and add it to the accumulator 
30 cout << "Enter score " << test << " for ";
31 cout << "student " << snum << ": ";
32 cin >> score;
33 total += score; // 
34 } // End inner loop
35 // Compute and display the student's average 
36 average = total / numTests;
37 cout << "The average score for student " << snum;
38 cout << " is " << average << "\n\n";
39 } // End outer loop
40 return 0;
41 }