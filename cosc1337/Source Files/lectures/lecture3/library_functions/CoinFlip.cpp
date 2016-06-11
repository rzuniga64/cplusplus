#include <iostream>

using namespace std;

int main()
{
    srand(time(0));
    cout << "0 = Tails, 1 = Heads." << endl;
    cout << "Your coin flip: " << rand() % 2 << endl;

    return 0;
}
