#include <iostream>
#include <fstream>
#include <vector>
#include "Student.h"

using namespace std;

int linearSearch(vector<Student> a, string searchForName, int & numCompares);

int main()
{
    vector<Student> students;
    Student student;

    ifstream inFile;
    inFile.open("students.txt");
    if (inFile.is_open()) {
        while (!inFile.eof()) {
            student.read(inFile);
            students.push_back(student);
        }
            
        // print array
        for (size_t i=0; i<students.size(); i++)
            students[i].display();
            
        // allow user to search array by name, print id num
        string toFind;
        int position = 0, numCompares;
        cout << "Enter name to search for: ";
        getline(cin, toFind);
        while(toFind != "")
        {
            // TODO: call function to find position
            position = linearSearch(students, toFind, numCompares);
            // TODO: print id number of student (if found)
            if (position >= 0)
                cout << "student id: " << students[position].getIDNumber() << endl;
            else
                cout << "student not found." << endl;
           
            // get name for next query
            cout << "Enter name to search for: ";
            getline(cin, toFind);
        }
    }
    else
        cout << "Error opening file for reading." << endl;
    
    system("PAUSE");
    return 0;
}

int linearSearch(vector<Student> a, string searchForName, int & numCompares)
{
    int pos = -1;
    numCompares = 0;
    for (size_t i=0; i<a.size() && pos < 0; i++) {
        numCompares++;
        if (a[i].getName() == searchForName)
            pos = i;
    }
    return pos;
}
