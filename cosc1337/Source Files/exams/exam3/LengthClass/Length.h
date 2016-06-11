#ifndef LENGTH_H
#define LENGTH_H

#include <iostream>
#include <string>

using namespace std;

/* Length class declaration
 */
class Length {
public:
	/* default constructor */
	Length();

	/* constructor:
	   inputs: length (double) and units (string)
	     valid units are "in", "cm", and "ft"
	 */
	Length(double lengthValue, string lengthUnits);

	/* setValue:
	   input: a new value
	   output: none, but the length is modified to have
	   the new length.  the units are unmodified.
	*/
	void setValue(double newValue);

	/* display:
	   displays the length on standard output.
	*/
	void display() const;

	/* read:
	   reads in the length and its units from
	   standard input.  assumes the user types
	   first the length and then the units.
	*/
	void read();

	/* lessThan:
	   input: another length
	   output: returns true if this length is less
	   than the other, and false otherwise
	*/
	bool lessThan(Length other) const;

	/* convertTo:
	   input: desired new units
	   output: none, but the length is converted
	   to the desired units.
	*/
	void convertTo(string newUnits);
private:
	/* These two functions are private utiliry
	   functions, used only by other functions
	   in the length class
	*/
	/* convertToCM
	   input: none
	   output: none, but length is converted from current
	   units to centimeters
	*/
	void convertToCM();
	/* convertFromCM
	   input: units to convert to
	   output: none, but length is converted to desired 
	   units if it was in centimeters to start with
	*/
	void convertFromCM(string newUnits);
	double value;
	string units;
	static const double CM_PER_INCH = 2.54;
	static const double CM_PER_FOOT = 30.48;
};

#endif
