#include <iostream>
#include <iomanip>

using namespace std;

void printInBox(string message);
void printLine(int n);

int main()
{
    string msg = "Hello, world!";
    printInBox(msg);
    system("PAUSE");
    return 0;
}

void printInBox(string message) 
{
    int messageLen = message.length();
    printLine(messageLen+4);
    cout << "* " << message << " *" << endl;
    printLine(messageLen+4);
}

void printLine(int len) 
{
    cout << setw(len+1) << setfill('*') << '\0' << endl;
}

