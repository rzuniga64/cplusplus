#include <iostream>

using namespace std;

int main()
{
    string word;
    int max;
    cout << "Enter the maximum number: ";
    cin >> max;
    srand(time(0));
    
    do 
    {
        cout << "Random number between 1 and " << max;
        cout << ": " << rand()% max + 1 << endl;
        cout << "Do again (yes/no)? ";
        cin >> word;
        while (word != "yes" && word != "no")
        {
            cout << "Please enter \"yes\" or \"no\": ";
            cin >> word;
        }
    } while (word == "yes");
    
    system("PAUSE");
    return 0;
}
