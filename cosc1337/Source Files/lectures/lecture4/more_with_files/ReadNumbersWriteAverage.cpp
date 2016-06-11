#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream infile;
    ofstream outfile;
    
    infile.open("three_numbers.txt");
    outfile.open("average.txt");
    
    int num1, num2, num3;
    infile >> num1 >> num2 >> num3;
    outfile << (static_cast<double>(num1)+num2+num3)/3 << endl;
    
    infile.close();
    outfile.close();
    
    system("PAUSE");
    return 0;
}
