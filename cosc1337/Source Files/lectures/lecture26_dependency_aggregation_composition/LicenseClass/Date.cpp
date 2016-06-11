#include "Date.h"
#include <ctime>

Date::Date(int dateMonth, int dateDay, int dateYear)
{
    month = dateMonth;
    day = dateDay;
    year = dateYear;
}

Date::Date()
{
    // get the time in seconds since Jan. 1, 1970
    time_t rawTime;
    time(&rawTime);
    // convert the time to local time
    struct tm * localTime = localtime(&rawTime);
    // convert to out class's format
    month = localTime->tm_mon + 1;
    day = localTime->tm_mday;
    year = localTime->tm_year + 1900;
}

// explicit code for the copy constructor that C++ gives you
/*
Date::Date(const Date & other) {
	month = other.month;
	day = other.day;
	year = other.year;
}
*/
void Date::readFromUser()
{
    cout << "Enter the month (by number, January = 1): ";
    cin >> month;
    cout << "Enter the day of the month: ";
    cin >> day;
    cout << "Enter the year: ";
    cin >> year;
}

void Date::display() const
{
    cout << month << " " << setw(2) << setfill('0');
    cout << day << ", " << year << endl;
}

bool Date::isEarlier(const Date & other) const
{
    bool earlier = false;
    if (year < other.year)
        earlier = true;
    else if (year == other.year && month < other.month)
        earlier = true;
    else if (year == other.year && month == other.month && day < other.day)
        earlier = true;
    return earlier;
}

