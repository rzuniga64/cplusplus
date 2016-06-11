#include <iostream>
#include "CashRegister.h"

using namespace std;

int main() {
    // demonstration of calling static function w/o making object
    // CashRegister::prettyPrintMoney(10.543);
    
	double itemPrice = 0.0;
	double amountPaid = 0.0;
	char another = 'y';
	bool paid = false;
	CashRegister cashRegister;

	while(toupper(another) == 'Y') {
		cashRegister.reset();
		itemPrice = -1;
		while(itemPrice != 0.0) {
			cout << "Enter item price (enter zero to stop): $";
			cin >> itemPrice;
			cashRegister.addItem(itemPrice);
		}
		cashRegister.calcTotalDue();
		
		paid = false;
		while(!paid) {
            cout << "Amount due: ";
            cashRegister.displayTotalDue();
			paid = cashRegister.calcDisplayChangeDue();
		}
		cout << "Continue (y/n)? ";
		cin >> another;
		cout << endl;
	}
	cout << endl;
	cashRegister.displayDrawers();

	system("PAUSE");
	return 0;
}
