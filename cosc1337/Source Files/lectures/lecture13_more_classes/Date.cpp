#include "Date.h"
#include <ctime>
#include <iostream>

Date::Date(int month, int day, int year) : month(month), day(day), year(year) {
	// should validate the parameters to guarantee our class invariant (valid date)
}

void Date::display() {
	cout << setw(2) << setfill('0') << month << '/' << setw(2) << day << '/' << setw(4) << year << endl;
}

void Date::readFromUser() {
	char slash;
	cin >> month >> slash >> day >> slash >> year;
	// should validate user's input
}

bool Date::isEarlierThan(const Date & otherDate) {
	bool isEarlier;
	if (year != otherDate.year) {
		isEarlier = year < otherDate.year;
		/*
		if (year < otherDate.year)
			isEarlier = true;
		else
			isEarlier = false;*/
	}
	else if (month != otherDate.month) 
		isEarlier = month < otherDate.month;
	else 
		isEarlier = day < otherDate.day;
	return isEarlier;
}