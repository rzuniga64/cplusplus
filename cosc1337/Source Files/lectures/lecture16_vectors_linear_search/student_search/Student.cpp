#include "Student.h"

void Student::display()
{
    cout << "Name: " << name << "; number: " << idNum << endl;
}

void Student::read(ifstream & inFile)
{
    getline(inFile, name, '#');
    inFile >> idNum;
    inFile.ignore();
}
