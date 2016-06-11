// This program attempts to average 2 test scores for each
2 // student in a class. However, it contains logic errors.
3 #include <iostream>
4 #include <string>
5 #include <iomanip>
6 using namespace std;
7
8 int main()
9 {
10 string name; // Student first name
11
12 int count = 1, // Student counter
13 score, // An individual score read in
14 totalScore = 0; // Total of a student's 2 scores
15 double average; // Average of a student's 2 scores
16
(program continues)

17 cout << fixed << showpoint << setprecision(1);
18 cout << "Enter the first name of student " << count
19 << " (or Q to quit): ";
20 cin >> name;
21
22 while (name != "Q" && name != "q")
23 {
24 // Get and validate the first score
25 cout << "Enter score 1: ";
26 cin >> score;
27 if (score <= 0 || score >= 100)
28 { cout << "Score must be between 0 and 100. Please reenter: ";
29 cin >> score;
30 }
31 totalScore += score; // Add the first score onto the total
32
33 // Get and validate the second score
34 cout << "Enter score 2: ";
35 cin >> score;
36 if (score <= 0 || score >= 100)
37 { cout << "Score must be between 0 and 100. Please reenter: ";
38 cin >> score;
39 }
40 totalScore += score; // Add the second score onto the total
41
42 // Calculate and print average
43 average = totalScore / 2;
44 cout << name << setw(6) << average << endl;
45
46 // Get the next student name
47 cout << "Enter the first name of student " << count++
48 << " (or Q to quit): ";
49 cin >> name;
50 }
51 return
}
