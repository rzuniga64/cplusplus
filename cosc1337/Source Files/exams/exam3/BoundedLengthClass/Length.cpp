#include "Length.h"

const double Length::CM_PER_INCH = 2.54;
const double Length::CM_PER_FOOT = 30.48;

Length::Length() {
    value = 1;
    units = "inches";
}

Length::Length(double lengthValue, const string & lengthUnits) {
    value = lengthValue;
    units = lengthUnits;
}

void Length::display(ostream & out) const {
    out << value << " " << units << endl;
}

bool Length::lessThan(const Length & other) const {
    Length otherCopy = other;
	otherCopy.convertTo(units);
	return value < other.value;
}

void Length::convertTo(const string & newUnits) {
    if (units != newUnits) {
        convertToCM();
        convertFromCM(newUnits);
    }
}

void Length::convertToCM() {
    if (units != "cm") {
        if (units == "inches") {
            value = value * CM_PER_INCH;
            units = "cm";
        }
        else if (units == "feet") {
            value = value * CM_PER_FOOT;
            units = "cm";
        }
        else
            cout << "Trying to convert from invalid units: " << units << endl;
    }
}

void Length::convertFromCM(const string & newUnits) {
    if (units == "cm") {
        if (newUnits == "inches") {
            value = value / CM_PER_INCH;
            units = "inches";
        }
        else if (newUnits == "feet") {
            value = value / CM_PER_FOOT;
            units = "feet";
        }
        else if (newUnits != "cm") 
            cout << "Trying to convert to invalid units: " << units << endl;
    }
    else
        cout << "Trying to convert from cm with current units " << units << endl;
}

// receives another Length object, and adds the other length to this length.
// The function should return a reference to *this. For example:
// Length l1(1, "inches"); Length␣l2(1, "cm"); l1.addOther(l2);
// cout<< "l1" << l1 << endl; // will display "1.3937 inches"
// If you are feeling bold, name the function operator+= instead of addOther

Length  & Length::addOther( Length other) {
	if (units != other.units) {
		other.convertTo(this->units);
		value += other.value;
	}
	return *this;
}

// If you are feeling bold, name the function operator+= instead of addOther
Length  & Length::operator+=( Length other) {
	if (units != other.units) {
		other.convertTo(units);
		value += other.value;
	}
	return *this;
}

ostream & operator<<(ostream & out, const Length &len) {
	len.display(out);
	return out;
}
