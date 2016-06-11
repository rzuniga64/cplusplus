#include "Student.h"

Student::Student(string studentName, int studentIDNum, double studentGPA) 
{
    name = studentName;
    idNum = studentIDNum;
    gpa = studentGPA;
	labCounter = 0;
}

void Student::display()
{
    cout << "Name: " << name << " (id " << idNum;
    cout << "), gpa: " << gpa << endl;
}

string Student::getName()
{
    return name;
}

int Student::getIDNum()
{
    return idNum;
}

double Student::getGPA()
{
    return gpa;
}

void Student::recordLabGrade(double grade)
{
	if (labCounter < NUM_LABS) 
	{
		labScores[labCounter] = grade;
		labCounter++;
	}
	else
	{
		cerr << "Attempt to store too many lab grades." << endl;
	}
}

double Student::getLabAverage()
{	
	double ave = 0.0;
	if (labCounter > 0)
	{
		double total = 0.0;
		for (int i=0; i<labCounter; i++)
			total += labScores[i];
		ave = total / labCounter;
	}
	return ave;
}