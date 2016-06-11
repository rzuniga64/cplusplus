#include "BoundedLength.h"

// The constructor should receive an additional maxLength parameter
// to specify the upper bound.
BoundedLength::BoundedLength(double value, const string & units, double upperBound)
: Length(value, units),
  maxLength(upperBound)
{
}

// The setValue function should cap the length at the maximum value
// if the function’s caller tries to set the length beyond the bound.
void BoundedLength::setValue(double newValue) {
	value = newValue;
	if (newValue > maxLength && maxLength != -1)
		value = maxLength;
}

// The convertTo function should convert the upper bound
// to the new units of the length.
void BoundedLength::convertTo(const string & newUnits) {
	// use a local Length variable to do the conversion of
	// the upper bound for us.
	Length boundLength(maxLength, units);
	boundLength.convertTo(newUnits);
	maxLength = boundLength.getValue();
	// then convert ourselves with inherited function
	Length::convertTo(newUnits);
}

// The addOther function from part b should also cap
// the length at the maximum value if the sum would otherwise
// go over the limit.
BoundedLength & BoundedLength::addOther( const Length & rhs) {
	Length::addOther(rhs);
	if (value > maxLength && maxLength != -1)
		value = maxLength;
	return * this;
}
