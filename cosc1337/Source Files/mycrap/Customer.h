#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class Customer {
public:
	/* Constructors */
	Customer();
	Customer(string customerName, int customerAcctNum);
	/* read
	   input: reference to an input file with customer data
	   output: none
	   effects: data members are set according to data in file. */
	void read(istream & inFile);
	/* display
	   input/output: none
	   effects: customer data is displayed on the screen. */
	void display() const;
	/* billToAccount
	   input: amount, output: none
	   effects: amount that customer owes is increased to reflect
	     additional new amount */
	void billToAccount(double amount);
	/* recordAccountPayment
	   input: amount, output: none
	   effects: amount that customer owes is descreased to reflect
  	     payment */
	void recordAccountPayment(double amount);
	/* getAmountOwed
	   returns amount customer currently owes */
	double getAmountOwed() const;
	/* getName
	   returns customer name */
	string getName() const;
	/* getAccountNumber
	   returns customer account number */
	int getAccountNumber() const;
private:
	string name;
	int acctNum;
	double amtOwed;
};

#endif
