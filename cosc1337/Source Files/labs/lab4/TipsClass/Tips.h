#pragma once
// FILE: Tips.h - header file for Tips class
//
// CONSTRUCTOR
//	Tips(double)
//		Input:	Receives value for data member taxRate.
//		Output: None, but modifies data member to have recieved value.
// 
//	CONST MEMBER FUNCTION (ACCESSORS)
//   void display() const
//		Input:	None
//		Output:	Displays to standard output the value of member variable taxRate.
//
//	MODIFICATION MEMBER FUNCTIONS (MUTATORS)
//   void computeTip()
//		Input:	The total bill amount and the tip rate.
//		Output:	The tip amount on the total bill amount plus tax.

#ifndef TIPS_H
#define TIPS_H

class Tips
{
public:
	Tips(double taxRate);
	void display() const;
	double computeTips(double totalBillAmount, double tipRate);

private:
	double taxRate;
};

#endif

