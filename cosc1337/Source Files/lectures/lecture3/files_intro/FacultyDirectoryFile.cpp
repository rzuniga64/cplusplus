#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main() 
{
    ofstream outFile;
    outFile.open("directory.txt", ios::out);
    
    int width = 10;
    outFile << left;
    outFile << setw(width) << "Name" << "Phone number" << endl;
    outFile << setw(width) << setfill('.') << "Black" << "3-3199" << endl;
    outFile << setw(width) << "Finney" << "3-3186" << endl;

    return 0;
}
