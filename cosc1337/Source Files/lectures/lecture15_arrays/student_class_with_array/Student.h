#include <iostream>
#include <string>

using namespace std;

const int NUM_LABS = 9;

class Student {
public:
    Student(string studentName, int studentIDNum, double studentGPA);
    void display();
    string getName();
    int getIDNum();
    double getGPA();
	void recordLabGrade(double grade);
	double getLabAverage();
private:
    string name;
    int idNum;
    double gpa;
	double labScores[NUM_LABS];
	int labCounter;
};
