#include <iostream>
#include <fstream>

using namespace std;

class Student {
public:
    Student() {};
    void read(ifstream & inFile);
    void display();
    string getName() {return name;};
    int getIDNumber() {return idNum;};
private:
    string name;
    int idNum;
};
