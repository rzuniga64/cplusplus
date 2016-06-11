// FILE: Temperature.h - header file for Temperature class
//
// CONSTRUCTOR
//   Temperature()
//		Input:	None
//		Output: None. But both data members are set to a reasonable value.
//				Temperature(double, char)
//		Input:	Receives values for both data members
//		Output: None, but modifies data members to have received values.
// 
//	CONST MEMBER FUNCTION (ACCESSORS)
//   void display() const
//		Input:	None
//		Output:	Displays to standard output in a readable format
//				both the temperature and degrees.
//
//	MODIFICATION MEMBER FUNCTIONS (MUTATORS)
//   void convert()
//		Input:	None
//		Output:	Converts the temperature from the current scale to the other scale.
//				If the temperature is currently in Fahrenheit, it should convert 
//				it to Celsius, and vice versa.

#ifndef TEMPERATURE_H
#define TEMPERATURE_H

using namespace std;

class Temperature
{
public:
	Temperature();
	Temperature(double, char);
	void display() const;
	void convert();

private:
	double temperature;
	char scale;
};

#endif
