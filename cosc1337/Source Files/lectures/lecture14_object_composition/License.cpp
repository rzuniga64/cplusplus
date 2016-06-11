#include "License.h"

License::License(const string & name, const string & type, int month, int day, int year) : name(name), type(type), expirationDate(month, day, year) {
}

License::License(const string & name, const string & type, const Date & expDate) : name(name), type(type), expirationDate(expDate) {
}

void License::display() const {
	Date today;
	if (expirationDate.isEarlier(today))
		cout << "***EXPIRED***! ";
    cout << name << " is licensed to practice ";
    cout << type << endl;
}
