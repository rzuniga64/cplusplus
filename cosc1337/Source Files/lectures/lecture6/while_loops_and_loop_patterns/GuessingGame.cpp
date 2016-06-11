#include <iostream>

using namespace std;

int main()
{
    int num, guess;
    int numGuesses = 0;
    
    srand(time(0));
    num = rand() % 100 + 1;
    
    cout << "Guess my number (1-100): ";
    cin >> guess;
    numGuesses++;
    while (guess != num) {
        if (guess > num)
            cout << "That guess is too high." << endl;
        else
            cout << "That guess is too low." << endl;
        cout << "Try again: ";
        cin >> guess;
        numGuesses++;
    }
    cout << "You got it in " << numGuesses << " guesses!" << endl;
    
    system("PAUSE");
    return 0;
}
