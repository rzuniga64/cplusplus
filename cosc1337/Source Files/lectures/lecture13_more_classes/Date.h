#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <iomanip>

using namespace std;

class Date {
public:
	Date(int month = 1, int day = 1, int year = 1970);
	void display();
	void readFromUser();
	bool isEarlierThan(const Date & otherDate);
private:
	int day;
	int month;
	int year;
};

#endif