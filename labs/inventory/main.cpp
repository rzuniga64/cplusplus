//************************************************************************
//
//	File:			main.cpp
//	Author:			Raul Zuniga
//	Description:	An inventory program utilizes an inventory class to 
//					buy and sell quantities of widgets.  The program is 
//					divided into three parts.
//
//					main.cpp      - the main program
//					inventory.h   - contains the inventory class
//					inventory.cpp - contains the class function 
//									declarations.
//				
//					This program creates an array of objects of the class
//					inventory.  The user is asked to input inventory data
//					for each object.  The user may then buy, sell or
//					display inventory data for a particular part number
//					for which he is interested.
//				
//					This program utilizes three different search methods--
//					linear, binary, and recursive binary to search for
//					the given part number in the array of objects.
//	Revision 1
//				  - Added overloaded plus(+), minus(-)and assignment(=) 
//					operators to the inventory class. The plus and minus 
//					operators are used to add/subtract an integer from 
//					the quantity on hand. The assignment operator is used
//					in a sorting routine of the object array.
//				  - A shoe class is derived from the inventory class and
//					an object is instantiated.  A boot class is derived 
//					from the shoe class and an object is instantiated.
//			      - File I/O has also been added to the program.
//				  - overloaded insertion and extraction operators for 
//					the inventory class were added and are used in 
//					conjuction with the file I/O.
//				  - The status function has been made a virtual function to 
//					allow all the classes to output their data. 
//				  - The sorting routine now uses a generic function through
//					template called Swapargs.
//
//************************************************************************
#include <fstream>
#include <iostream>
#include <iomanip>
#include "inventory.h"

using namespace std; 	

typedef unsigned short int USHORT;
	
#define SIZE 4
	
USHORT menu();
USHORT SearchMenu();
USHORT InputMenu();
USHORT OutputMenu();

void InputInventory( inventory arrayob[] );
void BubbleSort( inventory arrayob[] );
template <class X> void Swapargs(X &a, X &b );		
void DisplayInventory( inventory arrayob[] );
void BuyInventory( inventory arrayob[], int index, bool Filled );
void SellInventory( inventory arrayob[], int index, bool Filled );
int PartNumberSearch(inventory arrayob[]);
int LinearSearch( inventory arrayob[], int SearchKey);
int BinarySearch( inventory arrayob[], int low, int high, int SearchKey );
int RecursiveSearch( inventory arrayob[],int low, int high, int SearchKey );
void PrintHeader();
void PrintRow( inventory arrayob[], int low, int mid, int high );

ostream &header(ostream &stream);
ostream &sheader(ostream &stream);
ostream &bheader(ostream &stream);
ostream &line(ostream &stream);

int main()
{
	int index = -1;
	float value[SIZE] = {0.0,0.0,0.0,0.0};
	float val = 0.0;
	bool Filled = false;
		
	inventory ob[SIZE];
	inventory *p;
	
	shoe dob1;										//create a shoe object
	p = &dob1;										//pointer to base class points to shoe object
	val = dob1.value();
	cout << header << sheader << "\n" <<line;		//output a header
	p->status(val);									//output the shoe data
	cout << line;
	
	boot dob2;										//create a boot object
	p = &dob2;										//pointer to base class points to boot object
	val = dob2.value();
	cout << header << sheader << bheader << line;	//output a header
	p->status(val);									//output the boot data
	cout << line;
	
// An infinite loop utilizing a switch statement to allow you to input,buy
// sell and display inventory based off the choices selected from a menu.
	
	bool exit = false;
	for (;;)
	{
	
		USHORT choice = menu();
		switch(choice)
		{	
			case(1):
				InputInventory( ob );				//input inventory data
				Filled = true;
				break;
			case(2):
				BuyInventory( ob,index,Filled);		//buy inventory
				break;
			case(3):
				SellInventory( ob,index,Filled);	//sell inventory
				break;
			case(4):	
				DisplayInventory( ob );				//display inventory
				break;
			case(5):
				continue;							//redisplay the menu
				break;
			case(6):
				exit = true;						//exit the menu
				break;
			default:
				cout << "Please select again!\n\n";
				break;
		}
		
		if (exit) break;							//end forever loop
	}

	return 0;
}


USHORT menu()
{

// Create a menu that will allow you to buy and sell quantities of inventory
// and display the inventory's current status.

	USHORT choice;
	
	cout << "\n";
	cout << " ****   Widget Inventory Menu   ****\n\n";
	cout << " **** Programmed by: Roy Zuniga ****\n\n";
	cout << "(1) Input inventory data.\n";
	cout << "(2) Buy a widget.\n";
	cout << "(3) Sell a widget.\n";
	cout << "(4) Current inventory status.\n";
	cout << "(5) Redisplay menu.\n";
	cout << "(6) Quit.\n\n";
	cout << ": ";
	cin  >> choice;
	cout << "\n";

	return choice;
}

// InputInventory allows the user to fill the inventory array with data for each object.
void InputInventory( inventory arrayob[] )
{
    bool exit = false;
    while (exit == false)
    {
        USHORT choice = InputMenu();
        switch(choice)
        {
            case(1):
                for (int i = 0; i < SIZE; i++)
                    arrayob[i].fillit();
                exit = true;
                break;

            case(2): {
                cout << "Accessing input file...\n";
                ifstream infile("lab3.dat", ios::in);            //open file for input
                if (!infile) {
                    cerr << "Input file could not be opened" << endl;
                    exit;
                }
                while (!infile.eof()) {
                    for (int i = 0; i < SIZE; i++)
                        infile >> arrayob[i];            //overloaded insertion operator
                }
                infile.close();
                exit = true;
                break;
            }
            default:
                cout << "Please select again!\n\n";
                break;
        }
    }

    BubbleSort( arrayob );
}

USHORT InputMenu()
{

// The InputMenu function creates a menu that will allow you decide
// if the user would like to input data from the keyboard or a file.

	USHORT choice;

	cout << " ****      Input Device Menu     ****\n\n";
	cout << " ****  Programmed by: Roy Zuniga ****\n\n";
	cout << "Please select input device: \n";
	cout << "(1) Keyboard.\n";
	cout << "(2) File Input.\n";
	cout << ": ";
	cin  >> choice;
	cout << "\n";

	return choice;
}

void BubbleSort( inventory arrayob[]  )
{	

//Bubblesort sorts an array in ascending order

	cout << "Sorting......" << endl;
	for ( int i=0; i< SIZE-1; i++)
		for ( int j=0; j<SIZE-i-1; j++)
			if ( arrayob[j].GetPartNumber() > arrayob[j+1].GetPartNumber() )
				Swapargs(arrayob[j], arrayob[j+1]);	
}

template <class X> void Swapargs(X &a, X &b)
{

//Swapargs exchanges the elements of an array

	X temp = a;
	a = b;
	b = temp;
}

void DisplayInventory( inventory arrayob[] )
{

// DisplayInventory allows the user to display the inventory array.
	
	bool exit = false;
	while (exit == false)
	{
		USHORT choice = OutputMenu();
		switch(choice)
		{
			case(1):
				cout << header << "\n" << line;
				for (int i=0; i<SIZE; i++)
				{
					cout << arrayob[i];		
					cout << "\n";
				}
				cout << line;
				exit = true;
				break;
			case(2):
            {
				cout << "Accessing output file...\n";
				ofstream fout( "lab3.out");		 	//open file for output
				if (!fout) {cerr << "Output file could not be opened" << endl; exit;}
				fout << header << "\n" << line;
				for (int i=0; i<SIZE; i++)
				{
					fout << arrayob[i];				//overloaded insertion operator
					fout << "\n";
				}
				fout << line;
				fout.close();
				exit = true;
				break;
            }
            default:
				cout <<"Please select again!\n\n";
				break;
		}
	}
}

USHORT OutputMenu()
{

// The InputMenu function creates a menu that will allow you decide
// if the user would like to input data from the keyboard or a file.

	USHORT choice;
	
	cout << " ****     Output Device Menu     ****\n\n";
	cout << " ****  Programmed by: Roy Zuniga ****\n\n";
	cout << "Please select output device: \n";
	cout << "(1) Console.\n";
	cout << "(2) File Output.\n";
	cout << ": ";
	cin  >> choice;
	cout << "\n";

	return choice;
}

void BuyInventory( inventory arrayob[], int index, bool Filled )
{

// BuyInventory allows the user to buy inventory for a particular part number if 
// inventory data has already been entered.

	if (Filled) 
		index = PartNumberSearch(arrayob);
	else
		cout << "Please enter inventory data first!\n ";
						
	if ( index != -1 ) 	
		arrayob[index] = arrayob[index] + arrayob[index].buy();	//overloaded +/= operators	
	else
		cout << "Part number was not found in inventory!\n ";
}

void SellInventory( inventory arrayob[], int index, bool Filled )
{

// SellInventory allows the user to sell inventory for a particular part number if
// inventory data has already been entered.

	if (Filled) 
		index = PartNumberSearch(arrayob);
	else
		cout << "Please enter inventory data first!\n ";
					
	if ( index != -1 ) 
	{
		arrayob[index] = arrayob[index] - arrayob[index].sell(); //overloaded +/= operators			
	}
	else
		cout << "Part number was not found in inventory!\n ";
}

int PartNumberSearch(inventory arrayob[])
{

// The PartNumberSearch function utilizes a switch statement to allow you
// to choose different search methods to find the index of an inventory 
// part number stored in an array of objects. The desired part number is a
// private data member of one of the objects.

	int DesiredPart; 
	int first = 0;
	int index = -1;
	int last = SIZE-1;
	
	cout << "Please enter the desired part number: ";
	cin  >> DesiredPart; 
	cout << "\n";
		
	while (index == -1)
	{
		USHORT choice = SearchMenu();
		switch(choice)
		{
			case(1):
				index = LinearSearch( arrayob, DesiredPart );	
				break;
			case(2):
				PrintHeader();
				index = BinarySearch( arrayob, first, last, DesiredPart );
				break;
			case(3):
				PrintHeader();
				index = RecursiveSearch( arrayob, first, last, DesiredPart );
				break;
			default:
				cout <<"Please select again!\n\n";
				break;
		}
	} 
	return index;
}

USHORT SearchMenu()
{

// The SearchMenu function creates a menu that will allow you to search
// for a part number so it can be bought,sold or it's inventory status 
// can be displayed.

	USHORT choice;
	
	cout << " ****   Part Number Search Menu  ****\n\n";
	cout << " ****  Programmed by: Roy Zuniga ****\n\n";
	cout << "(1) Linear Search.\n";
	cout << "(2) Binary Search.\n";
	cout << "(3) Recursive Search.\n";
	cout << ": ";
	cin  >> choice;
	cout << "\n";

	return choice;
}

int LinearSearch( inventory arrayob[], int SearchKey )
{

// The Linear Search function performs a linear search of an array containing ordered 
// integer data, returning -1 if the item is not found, returning 1 the index of the 
// array if the item is found.

	for (int index=0; index<SIZE; index++)
		if ( SearchKey == arrayob[index].GetPartNumber() )			//search array
			return index;											//match
			
	return -1;
}

int BinarySearch( inventory arrayob[], int low, int high, int SearchKey )
{
// The BinarySearch function performs a binary search of an array containing ordered 
// integer data, returning -1 if the item is not found, returning the index of the 
// array if the item is found.
   
	int middle;														//search area's midpoint
	
	while ( low <= high )											
	{
		middle = ( low + high )/2;
		
		PrintRow( arrayob, low, middle, high );
		
		if ( SearchKey == arrayob[middle].GetPartNumber() )			//match
			return middle;
		else if ( SearchKey < arrayob[middle].GetPartNumber() )
			high = middle - 1;										//search low end of array
		else
			low = middle + 1;										//search high end of array
	}
	
	return -1;														//no match
}

int RecursiveSearch( inventory arrayob[],int low, int high, int SearchKey )
{

// The RecursiveSearch function uses a recursive algorithm to perform a binary search
// of an array containing ordered integer data, returning -1 if the item is not found, 
// returning the index of the array if the item is found.

	int middle;														//search area's midpoint
	
	while (low <= high )
	{
		middle = (low + high)/2;
		
		PrintRow( arrayob, low, middle, high );
		
		if ( SearchKey==arrayob[middle].GetPartNumber() )
			return middle;											//match
		else if ( SearchKey < arrayob[middle].GetPartNumber() )	
			return RecursiveSearch( arrayob, low, middle-1, SearchKey ); //search high end of array		
		else if ( SearchKey > arrayob[middle].GetPartNumber() )
			return RecursiveSearch( arrayob, middle+1, high, SearchKey );//search high end of array
	}
	return -1;														//no match
}

void PrintHeader()
{
// PrintHeader prints a header for output of the search routine

	cout << "\nSubscripts:\n";
	for ( int i=0; i<SIZE; i++)
		cout << setw(3) << i << ' ';
	cout << '\n';
	
	for ( int i=1; i<=4*SIZE; i++ )
		cout << '-';
		
	cout << endl;		
}

void PrintRow( inventory arrayob[], int low, int mid, int high )
{
//PrintRow prints one row of output showing the current 
//part of the array being processed in the search routine.

	for ( int i=0; i<SIZE; i++ )
		if ( i < low || i > high )
		   cout << "    ";
		else if ( i==mid )											//mark the middle value
			cout << setw(3) << arrayob[i].GetPartNumber() << '*';
		else
			cout << setw(3) << arrayob[i].GetPartNumber() << ' ';
			
		cout << "\n\n";	 
}

ostream &header(ostream &stream)
{
// function prints an inventory header

	stream << setw(8) << "Part No."
		   << setw(12) << "Quantity"
	       << setw(8) << "Cost"
	       << setw(9) << "Price"
	       << setw(9) << "Value"
	       << setw(15) << "Description";
}

ostream &sheader(ostream &stream)
{
// function outputs a shoe class header

	stream << setw(8) << "Size"
	       << setw(9) << "Color";
}

ostream &bheader(ostream &stream)
{
// function outputs a boot class header

	stream << setw(11) << "Boot Type" 
	       << setw(5) << "Sex\n";
}

ostream &line(ostream &stream)
{
// function prints a line of asterisks.

	for (int i=0;i<79; i++)
	stream << '*';
	stream << "\n";
}