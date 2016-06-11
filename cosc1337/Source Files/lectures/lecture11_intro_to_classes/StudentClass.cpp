#include <iostream>

using namespace std;

class Student {
public:
    Student(string studentName, int studentIDNum, double studentGPA);
    void display();
    string getName();
    int getIDNum();
    double getGPA();
private:
    string name;
    int idNum;
    double gpa;
};

Student::Student(string studentName, int studentIDNum, double studentGPA)
{
    name = studentName;
    idNum = studentIDNum;
    gpa = studentGPA;
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

int main()
{
    /*
    Student student;
    student.display();
    cout << student.getGPA() << endl;
    */
    Student student1("Albert Einstein", 1234567, 2.1);
    Student student2("Neil deGrasse Tyson", 7564534, 3.92);
    
    system("PAUSE");
    return 0;
}
