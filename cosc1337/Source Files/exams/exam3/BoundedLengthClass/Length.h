#ifndef LENGTH_H
#define LENGTH_H

#include <iostream>

using namespace std;

class Length {
public:
    Length();
    Length(double lengthVal, const string & lengthUnits);
    void setValue(double newValue);
    double getValue() {return value;}
    void display(ostream & out=cout) const;
    bool lessThan(const Length & other) const;
    void convertTo(const string & newUnits);
    Length  & addOther(Length other);
    Length  & operator+=(Length other);
protected:
    void convertToCM();
    void convertFromCM(const string & newUnits);
    double value;
    string units;
	static const double CM_PER_INCH;
	static const double CM_PER_FOOT;
};

ostream & operator<<(ostream & out, const Length &len);

#endif
