#include "Date.h"
#include <string>

using namespace std;

class License {
    public:
        License(const string & name, const string & type, int month, int day, int year);
        License(const string & name, const string & type, const Date & expDate);
        void display() const;
    private:
        string name;
        string type;
        Date expirationDate;
};
