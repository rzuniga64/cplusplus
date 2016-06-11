#ifndef CONTESTANT_H
#define CONTESTANT_H

#include <iostream>
#include <string>

using namespace std;

class Contestant{
public:
    // add member function prototypes here
	Contestant(string fname, string lname, int myguess);
	int getGuess();
	void display();

private:
    string firstName;
    string lastName;
    int guess;
};

#endif
