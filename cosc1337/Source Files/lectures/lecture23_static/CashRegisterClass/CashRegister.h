#ifndef CASH_REGISTER_H
#define CASH_REGISTER_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

class CashRegister {
public:
	CashRegister();
	
	/* mainLoop
	   prompts the user to enter purchases, calculates the
	   amount due, calculates change, and keeps track of 
	   the number of each type of currency available. */
    void mainLoop();

    // utility function for printing amounts of money nicely
    // public just 'cause it's a nifty function to have
	static void prettyPrintMoney(double amount);
	// static function for changing the tax rate
	static void setTaxRate(double newRate) {taxRate = newRate;};
	
private:
	/* reset
	   Resets the total price of purchased items to zero.
	   Should be called before ringing up each customer. */
	void reset();

	/* addItem
	   Adds an item price to the total owed by the customer. */
	void addItem(double itemPrice);

    void calcTotalDue();

	/* displayTotalDue
	   Displays the total due currently. */
	void displayTotalDue();

	/* calcDisplayChangeDue
	   input: none
	   output: Boolean indicating whether the customer paid enough
	   Calculates how much of each type of change is due back
	   to the customer, based on the total due and the amount paid. */
	bool calcDisplayChangeDue();
	
	/* displayDrawers
	   input: none
	   output: none
	   side effects: displays current state of drawers */
	void displayDrawers();

	static const int NUM_SLOTS = 10;
	static const string unitNames[NUM_SLOTS];
	static const int unitValues[NUM_SLOTS];
	int amountInSlots[NUM_SLOTS];
	int transactionSlots[NUM_SLOTS];
	static double taxRate;
	double total;
};

#endif
