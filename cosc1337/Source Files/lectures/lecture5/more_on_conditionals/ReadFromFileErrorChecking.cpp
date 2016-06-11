// FileRead.cpp
// An example of reading in from a file.
#include <iostream>
#include <fstream>

using namespace std;

int main() 
{
    string filename;
    cout << "Enter the name of the file: ";
    cin >> filename;
    
    ifstream inFile;
    inFile.open(filename.data());  
    
    if (inFile)
    {
        string str = "";
        getline(inFile, str);  // reads in the whole first line
        cout << "Here's what's in the file: " << str << endl; 
    }
    else
        cout << "Error opening " << filename << " for reading." << endl;
    
    inFile.close();
    
    system("PAUSE");
    return 0;
}
