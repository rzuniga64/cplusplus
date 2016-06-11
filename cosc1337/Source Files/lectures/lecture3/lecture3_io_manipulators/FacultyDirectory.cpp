#include <iostream>
#include <iomanip>

using namespace std;

int main() 
{
    int width = 30;
    cout << left << setw(width) << "Name" << "Phone number" << endl;
    cout << setw(width) << setfill('.') << "Black" << "3-3199" << endl;
    cout << setw(width) << "Finney" << "3-3186" << endl;
    cout << setw(width) << "Kohls" << "3-3185" << endl;

    return 0;
}
