//************************************************************************
//
//	Assignment:		Exercise 3
//	File:			inventory.h
//	Author:			Raul Zuniga
//	Due Date:		July 19, 2000
//	Description:	Contains:
//					- inventory class which is inherited
//					- shoe class which is derived from inventory class
//					- boot class which is derived from shoe class.
//			
//			 .      
//************************************************************************

#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
using namespace std;

class inventory
{
protected:
	int PartNumber;						//part number
	int quantity;						//quantity on hand
	float cost;							//the amount the company pays for the item
	float price;						//the amount the company sells the item 
	char *PartDescr;					//part description
public:
	inventory();						//constructor
	inventory( const inventory &a );	//copy constructor
	~inventory();						//destructor
	void fillit();
	int buy();
	int sell();
	virtual void status(float v);		//virtual function
	float value();
	int GetPartNumber();
	inventory operator+( int i );		//overloaded + operator
	inventory operator-( int i );		//overloaded - operator
	inventory operator=( inventory ob2);//overloaded = operator
	friend istream &operator>>(istream &stream, inventory &ob);
	friend ostream &operator<<(ostream &stream, inventory &ob);
};

class shoe : public inventory			//shoe is derived from inventory
{
protected:
	int size;
	char color[15];
public:
	shoe();
	~shoe();
	void status(float v);				//virtual function
};

class boot: public shoe 				//boot is derived from shoe
{
	char type[10];
	char sex;
public:
	boot();
	~boot();
	void status(float v);				//virtual function
};

#endif