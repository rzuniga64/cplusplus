#include <iostream>

using namespace std;

class ClassWithPointer {
public:
    ClassWithPointer(int val);
    ClassWithPointer(const ClassWithPointer & other);
    ~ClassWithPointer();
    ClassWithPointer & operator=(const ClassWithPointer & rhs);
    void display();
private:
    int * intPtr;
};

ClassWithPointer::ClassWithPointer(int val) {
    intPtr = new int;
    *intPtr = val;
}

ClassWithPointer::ClassWithPointer(const ClassWithPointer & other) {
    intPtr = new int;
    *intPtr = *(other.intPtr);
}

ClassWithPointer & ClassWithPointer::operator=(const ClassWithPointer & rhs) {
    if (this != &rhs) {
        delete intPtr;
        intPtr = new int;
        *intPtr = *(rhs.intPtr);
    }
    return *this;
}

ClassWithPointer::~ClassWithPointer() {
    delete intPtr;
}

void ClassWithPointer::display() {
    cout << "pointer: " << intPtr << endl;
    cout << "pointer points to: " << *intPtr << endl;
}

int main()
{
    ClassWithPointer o1(4);
    ClassWithPointer o2(o1);
    ClassWithPointer o3(6);
    
    o3 = o1;
    
    system("PAUSE");
    return 0;
}
