#include "Length.h"

/* validUnits:
   global utility function for determining whether a 
   string is a valid units string.
*/
bool validUnits(string units);

bool validUnits(string units) 
{
	return (units == "ft" || units == "in" || units == "cm");
}

Length::Length() 
{
	value = 0.0;
	units = "cm";
}

Length::Length(double lengthValue, string lengthUnits) 
{
	value = lengthValue;
	if (validUnits(lengthUnits))
		units = lengthUnits;
	else 
	{
		cout << "Length constructor error: " << lengthUnits;
		cout << " invalid;" << endl;
		units = "cm";
	}
}

void Length::setValue(double newValue)
{
	value = newValue;
}

void Length::display() const
{
	cout << value << " " << units;
}

void Length::read()
{
	cin >> value >> units;
}

bool Length::lessThan(Length other) const
{
	if (units != other.units)
		other.convertTo(units);
	return (value < other.value);
}

void Length::convertTo(string newUnits)
{
	convertToCM();
	convertFromCM(newUnits);
}

void Length::convertToCM()
{
	if (units == "ft") 
		value = CM_PER_FOOT * value;
	else if (units == "in")
		value = CM_PER_INCH * value;
	units = "cm";
}

void Length::convertFromCM(string newUnits)
{
	if (units == "cm") 
	{
		if (newUnits == "in")
			value = value / CM_PER_INCH;
		else if (newUnits == "ft")
			value = value / CM_PER_FOOT;
		units = newUnits;
	}
	else
		cout << "convertFromCM error: length is not in centimeters." << endl;
}
