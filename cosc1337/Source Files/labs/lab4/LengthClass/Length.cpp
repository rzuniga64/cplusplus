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

void Length::display() 
{
	cout << value << " " << units;
}

void Length::read() 
{
	cin >> value >> units;
}

bool Length::lessThan(Length other) 
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
	const double CM_PER_IN = 2.54;
	const double CM_PER_FT = 30.48;
	if (units == "ft") 
		value = CM_PER_FT * value;
	else if (units == "in")
		value = CM_PER_IN * value;
	units = "cm";
}

void Length::convertFromCM(string newUnits) 
{
	const double CM_PER_IN = 2.54;
	const double CM_PER_FT = 30.48;
	if (units == "cm") 
	{
		if (newUnits == "in")
			value = value / CM_PER_IN;
		else if (newUnits == "ft")
			value = value / CM_PER_FT;
		units = newUnits;
	}
	else
		cout << "convertFromCM error: length is not in centimeters." << endl;
}
