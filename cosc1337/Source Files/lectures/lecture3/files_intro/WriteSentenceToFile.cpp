// WriteFile.cpp
// Reads in a sentence from the user, and writes it to a test file.
#include <iostream>
#include <fstream>

using namespace std;

int main() 
{
    string sentence = "";
    cout << "Enter a sentence: ";
    getline(cin, sentence);
    
    ofstream outFile;
    outFile.open("testFile.txt");
   
    outFile << sentence << endl;
    
    outFile.close();
   
    return 0;
}
