#include "Student.h"

int main()
{
    Student student1("Albert Einstein", 1234567, 2.1);
    Student student2("Neil deGrasse Tyson", 7564534, 3.92);
    int num1 = 0;
    int num2 = 0;
    
    student1.display();
    student2.display();
    
    cout << "Student 1's name is: " << student1.getName() << endl;

	double grade;
	cout << "Enter a grade for student 1 (-1 to quit): ";
	cin >> grade;
	while (grade != -1.0) 
	{
		student1.recordLabGrade(grade);
		cout << "Enter a grade for student 1 (-1 to quit): ";
		cin >> grade;
	}
	cout << "Student 1's lab average: " << student1.getLabAverage() << endl;
    
    return 0;
}
