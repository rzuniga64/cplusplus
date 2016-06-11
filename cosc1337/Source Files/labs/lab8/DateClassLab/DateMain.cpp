#include "Date.h"

int main()
{
	int days;
	Date date1(12, 22, 2014);
	days = date1.numDays(6, 2012);
	date1.display(cout);
	cout << endl << days << endl;
	Date date2(12,22,2014);
	if (datesAreEqual(date1, date2)) {
		date1.display(cout);
		cout << " is equal to ";
		date2.display(cout);
		cout << endl;
	}

    Date d1(11, 31, 2011);
    Date d2;
    d2.readFromUser();
    
    cout << endl << "d1: ";
    d1.display();
    cout << endl << "d2: ";
    d2.display();
    cout << endl << endl;
    
    d1.display();
    if (d1.isEarlierThan(d2))
        cout << " is before ";
    else 
        cout << " is after or the same as ";
    d2.display();
    cout << endl;
    
    return 0;
}
