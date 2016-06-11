#include "Date.h"

int main()
{
    Date date(2, 26, 2014), date2;
    
    date.display();
    
	cout << "Enter a correctly formatted date: ";
	date2.readFromUser();

	cout << "Here's what I read: ";
	date2.display();

	date.display();
	if (date.isEarlierThan(date2))
		cout << " is earlier than ";
	else
		cout << " is at least as late as ";
	date2.display();

    return 0;
}
