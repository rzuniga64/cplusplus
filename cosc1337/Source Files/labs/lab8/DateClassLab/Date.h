#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Date {
	friend bool datesAreEqual(const Date & date1, const Date & date2);
	friend ostream & operator<<(ostream & out, const Date & date);
public:
    Date();
    Date(int month, int day, int year);
    //const member function
    void display(ostream & out=cout) const;
    void readFromUser();
    bool isEarlierThan(const Date & other) const;
    static int numDays(int month, int year);
private:
    static const int NUM_MONTHS = 12;
    static const string monthNames[NUM_MONTHS];
    static const int monthNumDays[12];

    int month;
    int day;
    int year;
};
