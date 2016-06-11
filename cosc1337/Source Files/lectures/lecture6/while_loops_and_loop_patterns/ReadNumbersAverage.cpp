// ReadNumbersAverage.cpp
// Reads in numbers from the file numbers.txt and
// computes the average of the numbers in the file.
#include <iostream>
#include <fstream>

using namespace std;

int main() 
{
    double num, total = 0, numNums = 0;
    ifstream infile;
    infile.open("numbers.txt");
    
    if (infile)
    {
        while(infile >> num)
        {
            numNums++;
            total += num;
        }
        cout << "Average: " << total / numNums << endl;
    }
    else
        cout << "Error opening numbers.txt for reading." << endl;
    
    system("PAUSE");
    return 0;
}
