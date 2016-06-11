// PointerDemo.cpp
// File for doing random demonstrations of the use of pointers
#include <iostream>

using namespace std;

int main() {
	int num = 12;
    int * numPtr = &num;

	cout << "value of num: " << num << endl;
	cout << "address of num: " << &num << endl;
	cout << "address stored in numPtr: " << numPtr << endl;
	cout << "address of numPts: " << &numPtr << endl;

	system("PAUSE");
	return 0;
}
