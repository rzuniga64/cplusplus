#include <iostream>

using namespace std;

class ClassWithPointer {
    public:
        ClassWithPointer(int val);
        ~ClassWithPointer();
        void display();
    private:
        int * intPtr;
};

ClassWithPointer::ClassWithPointer(int val) {
    intPtr = new int;
    *intPtr = val;
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
    ClassWithPointer o(6);
    o.display();
    
    system("PAUSE");
    return 0;
}
