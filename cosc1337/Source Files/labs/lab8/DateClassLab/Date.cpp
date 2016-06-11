#include "Date.h"
#include <ctime>

const string Date::monthNames[Date::NUM_MONTHS] = {"January", "February", 
												   "March", "April", "May", 
												   "June", "July", "August", 
												   "September", "October", 
                                                   "November", "December"};
const int Date::monthNumDays[Date::NUM_MONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
    month = 1;
    day = 1;
    year = 2011;
}

Date::Date(int month, int day, int year) {
    this->year = year;
    this->month = month;
    this->day = day;

    if (numDays(this->month,this->year) == -1) {
    	this->year = (this->year < 1) ? 1 : (this->year > 2014 ? 2014 : this-> year);
    	this->month = (this->month < 1) ? 1 : (this->month > 12 ? 12: this->month);
    	if (this->month != month)
    		this->day = Date::monthNumDays[this->month-1];
	}
}

void Date::display(ostream & out) const {
    if (month >= 1 && month <= NUM_MONTHS)
        out << monthNames[month-1] << " ";
    else
        out << "Invalid ";
    out << day << ", " << year;
}

void Date::readFromUser() {

    cout << "Enter month: ";
    cin >> month;
    cout << "Enter day: ";
    cin >> day;
    cout << "Enter year: ";
    cin >> year;

    int tempMonth = month;
    int tempYear = year;

    if (numDays(this->month,this->year) == -1) {
    	this->year = (this->year < 1) ? 1 : (this->year > 2014 ? 2014 : this-> year);
    	this->month = (this->month < 1) ? 1 : (this->month > 12 ? 12: this->month);
    	if ((this->month != tempMonth) || (this->year != tempYear))
    		this->day = Date::monthNumDays[this->month-1];
	}
}

bool Date::isEarlierThan(const Date & other) const {
    bool isEarlier = false;
    if (year != other.year)
        isEarlier = year < other.year;
    else if (month != other.month)
        isEarlier = month < other.month;
    else
        isEarlier = day < other.day;
    return isEarlier;
}

int Date::numDays(int month, int year) {

	int numDaysOfMonth = -1;

	if (( month >= 1 && month <= 12) && (year >= 1 && year <= 2014)) {
		if ((year%4==0) && (month==2))
			numDaysOfMonth = (Date::monthNumDays[month-1])+1;
		else
			numDaysOfMonth = Date::monthNumDays[month-1];
	}
	return numDaysOfMonth;
}

bool datesAreEqual(const Date & date1, const Date & date2) {

	return ((date1.year == date2.year) && (date1.month == date2.month) && (date1.day == date2.day));
}

ostream & operator<<(ostream & out, const Date & date) {
	date.display(out);
	return out;
}
