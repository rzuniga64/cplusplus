#ifndef BOUNDED_LENGTH_H
#define BOUNDED_LENGH_H

#include "Length.h"

class BoundedLength : public Length {
public:
	BoundedLength(double value, const string & units, double upperBound = -1);
	void setValue(double len);
	void convertTo(const string & newUnits);
	BoundedLength & addOther( const Length & rhs);
private:
	double maxLength;
};

#endif
