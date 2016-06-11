#include <iostream>
#include <iomanip>

using namespace std;

class Date {
    public:
        Date(int dateMonth, int dateDay, int dateYear);
        Date();
		//Date(const Date & other);
        void readFromUser();
        void display() const;
        bool isEarlier(const Date & other) const;
    private:
        int month;
        int day;
        int year;
};
