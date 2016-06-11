#include "CashRegister.h"

/* non-member utility functions */
/* no particular reason that this is a non-member function while
   prettyPrintMoney is a member function.  Mostly just 'cause 
   printing money actually has something to do with cash registers
   and converting strings from plural to singular doesn't really. */
string pluralToSingular(string plural);

/* Initialize static data members */
const string CashRegister::unitNames[NUM_SLOTS] = {"hundreds", "fifties", 
                                                   "twenties", "tens", 
												   "fives", "ones", 
												   "quarters", "dimes", 
												   "nickels", "pennies"};
												   
const int CashRegister::unitValues[NUM_SLOTS] = {10000, 5000, 2000, 1000, 500, 
												 100, 25, 10, 5, 1};

double CashRegister::taxRate = 0.0825;

CashRegister::CashRegister() {
    // fill in cash register slots
    cout << "Enter initial amounts in drawers..." << endl;
    for (int i=0; i<NUM_SLOTS; i++) {
        cout << "Enter number of " << unitNames[i] << ": ";
        cin >> amountInSlots[i];
        transactionSlots[i] = 0;
    }
    cout << endl;
	reset();
}

void CashRegister::mainLoop() {
    double itemPrice = 0.0;
	double amountPaid = 0.0;
	char another = 'y';
	bool paid = false;

	while(toupper(another) == 'Y') {
		reset();
		itemPrice = -1;
		while(itemPrice != 0.0) {
			cout << "Enter item price (enter zero to stop): $";
			cin >> itemPrice;
			addItem(itemPrice);
		}
		calcTotalDue();
		
		paid = false;
		while(!paid) {
            cout << "Amount due: ";
            displayTotalDue();
			paid = calcDisplayChangeDue();
		}
		cout << "Continue (y/n)? ";
		cin >> another;
		cout << endl;
	}
	cout << endl;
	displayDrawers();
}

void CashRegister::reset() {
	total = 0.0;
}

void CashRegister::addItem(double itemPrice) {
	total += itemPrice;
}

void CashRegister::calcTotalDue() {
    total = total * (1.0 + taxRate);
}

void CashRegister::displayTotalDue() {
	prettyPrintMoney(total);
	cout << endl;
}

bool CashRegister::calcDisplayChangeDue() {
    double amountPaid = 0.0;
    int num = 0;
    cout << "Enter the amount paid: $";
    cin >> amountPaid;
    bool transactionGood = true;
    if (amountPaid >= total) {
        int centsDueBack = static_cast<int>(amountPaid * 100 - floor(total * 100 + 0.5));
        int centsPaid = static_cast<int>(amountPaid * 100);
        for (int i=0; i<NUM_SLOTS; i++)
            transactionSlots[i] = 0;
        // find out what bills are being added to the drawers
        for (int i = 0; i < NUM_SLOTS && centsPaid > 0; i++)
        {
            if (centsPaid >= unitValues[i]) {
                cout << "Enter number of " << unitNames[i] << ": ";
                cin >> num;
                if (centsPaid - num * unitValues[i] >= 0) {
                    transactionSlots[i] += num;
                    centsPaid -= num * unitValues[i];
                }
                else {
                    cout << "That is more than the customer paid..." << endl;
                    i--;
                }
            }
        }
        // calculate what needs to be removed from the drawers
        if (centsDueBack > 0) {
            cout << endl << "Change due: ";
            prettyPrintMoney(centsDueBack / 100.0);
            cout << endl;
            for (int i=0; i<NUM_SLOTS; i++) {
                num = centsDueBack / unitValues[i];
                if (amountInSlots[i]+transactionSlots[i] >= num)
                    transactionSlots[i] -= num;
                else {
                    //cout << "*** Not enough ";
                    //cout << unitNames[i];
                    //cout << "; substituting..." << endl;
                    num = amountInSlots[i]+transactionSlots[i];
                    transactionSlots[i] -= num;
                }
                // display the number to paid
                if (num > 0) {
                    cout << num << " ";
                    cout << (num == 1 ? pluralToSingular(unitNames[i]) : 
                    		 unitNames[i]);
                    cout << endl;
                }
                centsDueBack = centsDueBack - unitValues[i]*num;
            }
            // if we couldn't make change, don't update
            if (centsDueBack > 0) {
                cout << "*** Could not make change.  Try again..." << endl;
                transactionGood = false;
            }
            else {
                // update the actual drawers
                for (int i=0; i<NUM_SLOTS; i++)
                    amountInSlots[i] += transactionSlots[i];
            }
        }
	}
	else {
		cout << "*** Not enough paid. Customer still owes: ";
        cout << total - amountPaid << endl;
		transactionGood = false;
	}
	return transactionGood;
}

void CashRegister::displayDrawers() {
    double total = 0.0;
    cout << endl << "Cash register contents: " << endl;
    for (int i=0; i<NUM_SLOTS; i++) {
        cout << setw(4) << right << amountInSlots[i] << " ";
        cout << setw(8) << right;
        cout << (amountInSlots[i] == 1 ? pluralToSingular(unitNames[i]) : unitNames[i]);
        cout << " ($" << setw(7) << right;
        cout << (amountInSlots[i]*unitValues[i]) / 100.0 << ")" << endl;
        total += amountInSlots[i] * unitValues[i];
    }
    cout << "Total in drawer: $" << total / 100.0 << endl << endl;
}

void CashRegister::prettyPrintMoney(double amount) {
    amount = floor(amount * 100 + 0.5) / 100.0;
	cout << "$" << fixed << setprecision(2) << amount;
}

string pluralToSingular(string plural) {
	size_t len = plural.length();
	if (plural.substr(len-3, 3) == "ies")
		return plural.substr(0, len-3) + "y";
	else
		return plural.substr(0, len-1);
}

int round(double d) {
	return static_cast<int>(d+0.5);
}