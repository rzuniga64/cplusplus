#include <iostream>

using namespace std;

int main()
{
    string name = "";
    
    cout << "Enter your first and last name: ";
    //cin >> name;
    getline(cin, name);
    
    cout << "Name: " << name << endl;

    return 0;
}
