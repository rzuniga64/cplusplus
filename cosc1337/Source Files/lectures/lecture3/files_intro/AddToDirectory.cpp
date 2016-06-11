#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    ofstream outFile;
    outFile.open("directory.txt", ios::app);
    
    string name, number;
    cout << "Enter the name: ";
    getline(cin, name);
    cout << "Enter the number: ";
    getline(cin, number);
    
    outFile << left << setw(10) << setfill('.') << name << number << endl;
    
    return 0;
}
