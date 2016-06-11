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
    
    // on Dev, first declare file stream variable, then open the file
    ifstream inFile;
    inFile.open(filename.data());  // can leave out .data() in newer compilers
    
    // in newer visual studio installs, can combine the variable
    // declaration and the file opening, like so:
    //ifstream inFile(filename);  
    
    
    
    string str = "";
    //inFile >> str;  // reads in just the first word
    getline(inFile, str);  // reads in the whole first line
    cout << "Here's what's in the file: " << str << endl; 
    
    inFile.close();
    
    system("PAUSE");
    return 0;
}
