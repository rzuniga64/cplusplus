//*****************************************************************************
//
//	Assignment:		Exercise 3
//	File:			inventory.h
//	Author:			Raul Zuniga
//	Due Date:		July 19, 2000
//	Description:	Contains following member functions for three classes:
//					
//					inventory class
//					---------------
//					- constructor
//					- copy constructory
//					- destructor
//					- fillit()
//					- buy()
//					- sell()
//					- status(float v) 
//					- value()
//					- GetPartNumber()
//					- operator+( int i)
//					- operator-( int i)
//					- operator=( inventory ob2 )
//					- friend istream &operator>>(istream &stream, inventory &ob)
//					- friend ostream &operator<<(ostream &stream, inventory &ob)
//		
//					shoe class
//					----------
//					- constructor
//					- destructor
//					- status(float v)
//					
//					boot class
//					----------
//					- constructor
//					- destructor
//					- status (float v)
//			
//******************************************************************************

#include <iostream>
#include <iomanip>
#include "inventory.h"

using namespace std;

inventory::inventory()
{
	PartDescr = new char [40];
	if(!PartDescr)
	{
		cout << "Allocation error\n";
		exit;
	}
	cout << "Constructing the base class, no parameters\n\n";
	PartNumber = 0;
	quantity = 0;
	cost = 0.0;
	price = 0.0;
	strcpy( PartDescr, "Hello World");
}

inventory::inventory(const inventory &a)
{
//copy constructor

	PartDescr = new char [40];
	if(!PartDescr)
	{
		cout << "Allocation error\n";
		exit;
	}
	
	PartNumber = a.PartNumber;
	quantity = a.quantity;		
	cost = a.cost;		
	price = a.price; 
	strcpy( PartDescr, a.PartDescr);
	cout << "In copy constructor\n";	
}

inventory::~inventory()
{
	cout << "Destructing the base class\n\n";
	delete [] PartDescr;
}	

void inventory::fillit()
{
// Input the data for the data members of the class

	cout   << "\nInput the part number: ";
	cin    >> PartNumber ;
	cout   << "Input the quantity: ";
	cin    >> quantity ;
	cout   << "Input the cost of the item (e.g. 1.00): ";
	cin    >> cost;
	cout   << "Input the retail price: (e.g. 5.00): ";
	cin    >> price;
	cin.ignore();
	cout   << "Input a part description: ";
	cin.getline(PartDescr, 41);
	cout   << "\n";
}

int inventory::buy()
{
// buy increase the quantity on hand and changes the cost

	int q;
	float newcost = 0.0;
	
	cout << "Enter the quantity you want to buy: ";
	cin  >> q;
	if (q>0)
	{
		cout << "Enter the initial cost you paid for the item (e.g. $1.00); $";
		cin  >> newcost;
		cout << "\n";
		cost = newcost;
	}
	else
		cout << "\n";
		
	return q;
}

int inventory::sell()
{
// Sell decreases the quantity on hand and changes the price
// (the amount the company sells the item to the public)

	int q;
	float newprice = 0.0;
	
	for (;;)
	{
		cout << "Enter the quantity you want to sell: ";
		cin  >> q;
		if ((quantity-q) >=0 && q>0)
		{
			cout << "Enter the price which you sold the item (e.g. $5.00): $";
			cin  >> newprice;
			cout << "\n";
			price = newprice;
			break;
		}
		else if (q<=0)
		{
			cout << "\n";
			break;
		}
		else
			cout << "There is not enough inventory for that amount!\n";
	}
	
	return q;
}

void inventory::status(float v)
{
//virtual function, output the data in the class

	cout << "You must override this function!\n";
} 

float inventory::value()
{
// value returns the value of the part

	return quantity*price;
}

int inventory::GetPartNumber()
{
// GetPartNumber returns the part number

	return PartNumber;
}

inventory inventory::operator+( int i )
{
//overloaded + operator

	inventory temp;
	temp.PartNumber = PartNumber;
	temp.quantity = quantity + i;
	temp.cost = cost;
	temp.price = price;
	strcpy( temp.PartDescr, PartDescr );
	
	return temp;
}

inventory inventory::operator-( int i )
{
//overloaded - operator

	inventory temp;
	temp.PartNumber = PartNumber;
	temp.quantity = quantity - i;
	temp.cost = cost;
	temp.price = price;
	strcpy( temp.PartDescr, PartDescr );
	
	return temp;
}

inventory inventory::operator=(inventory ob2)
{
//Overloaded assignment(=) operator

	PartDescr = new char [40];
	if(!PartDescr)
	{
		cout << "Allocation error\n";
		exit;
	}
	PartNumber = ob2.PartNumber;
	quantity = ob2.quantity;
	cost = ob2.cost;
	price = ob2.price;
	strcpy( PartDescr, ob2.PartDescr );
	
	return *this;
}

istream &operator>>(istream &stream, inventory &ob)
{
// Input the data for the data members of the class

	stream >> ob.PartNumber ;
	stream >> ob.quantity ;
	stream >> ob.cost;
	stream >> ob.price;
	stream.ignore();
	stream.getline(ob.PartDescr, 41);
}

ostream &operator<<(ostream &stream, inventory &ob)
{		
// Output the current data in the class

	stream << setw(8)  << ob.PartNumber;	
	stream << setw(12) << ob.quantity;
	stream << setiosflags(ios::fixed);
	stream.precision(2);
	stream << setw(8)  << ob.cost;
	stream << setw(9)  << ob.price;
	stream << setw(9)  << ob.value();
	stream << setw(14) << ob.PartDescr;
}

shoe::shoe()
{
	cout << "Constructing shoe class\n\n";
	size = 0;
	strcpy( color, "white");
}

shoe::~shoe()
{
	cout << "Destructing shoe class\n\n";
}

void shoe::status(float v)
{
// Output the data in the class

	cout << setw(8) << PartNumber;	
	cout << setw(12) << quantity;
	cout << setiosflags(ios::fixed);
	cout.precision(2);
	cout << setw(8) << cost;
	cout << setw(9) << price;
	cout << setw(9) << v;
	cout << setw(15) << PartDescr;
	cout << setw(8) << size;	
	cout << setw(9) << color << endl;
}

boot::boot()
{
	cout << "Constructing boot class\n\n";
	strcpy( type, "cowboy");
	sex = 'M';
}

boot::~boot()
{
	cout << "Destructing boot class\n\n";
}

void boot::status(float v)
{
// Output the data in the class

	cout << setw(8) << PartNumber;	
	cout << setw(12) << quantity;
	cout << setiosflags(ios::fixed);
	cout.precision(2);
	cout << setw(8) << cost;
	cout << setw(9) << price;
	cout << setw(9) << v;
	cout << setw(15) << PartDescr;
	cout << setw(8) << size;	
	cout << setw(9) << color;
	cout << setw(11) << type;
	cout << setw(4) << sex << endl;
}
