#include <iostream>

using namespace std;

int main()
{
    int roll1, roll2;
    srand(time(0));
    roll1 = rand() % 6 + 1;
    // ERROR: Don't re-seed your random number generator within
    // the same second, or you'll get the same random number.
    // In general, you want to seed your random number generator
    // once at the beginning of the program and then never again.
    //srand(time(0));
    roll2 = rand() % 6 + 1;
    
    cout << roll1 << " " << roll2 << endl;
    //cout << "Sum of dice: " << roll1 + roll2 << endl;
    
    return 0;
}
