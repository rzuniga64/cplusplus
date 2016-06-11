#include "Customer.h"
#include <iostream>

using namespace std;

Customer::Customer() {
	name = "";
	acctNum = -1;
	amtOwed = 0.0;
}

Customer::Customer(string customerName, int customerAcctNum) {
	name = customerName;
	acctNum = customerAcctNum;
	amtOwed = 0.0;
}

void Customer::read(istream & inFile) {
	// read in name
	getline(inFile, name, ',');
	inFile >> acctNum;
	// ignore comma
	inFile.ignore(20, ',');
	inFile >> amtOwed;
	// ignore any more characters in the line
	inFile.ignore(20, '\n');
}

void Customer::display() const {
	cout << name << " (#" << acctNum << ")";
	cout << " owes: $" << fixed << setprecision(2) << amtOwed << endl;
}

void Customer::billToAccount(double amount) {
	amtOwed += amount;
}


void Customer::recordAccountPayment(double amount) {
	amtOwed -= amount;
}

double Customer::getAmountOwed() const {
	return amtOwed;
}

string Customer::getName() const {
	return name;
}

int Customer::getAccountNumber() const {
	return acctNum;
}
