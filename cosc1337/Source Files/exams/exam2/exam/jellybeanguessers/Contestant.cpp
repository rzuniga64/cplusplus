#include "Contestant.h"
#include <iostream>

Contestant::Contestant(string fname, string lname, int myguess)
{
	firstName = fname;
	lastName = lname;
	guess = myguess;
}

int Contestant::getGuess()
{
	return guess;
}

void Contestant::display()
{
	cout << firstName << " " << lastName << endl;
}