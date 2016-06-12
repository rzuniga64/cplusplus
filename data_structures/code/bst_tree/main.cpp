//************************************************************************
//
//	Assignment:		Exercise 5
//	File:			main.cpp
//	Author:			Raul Zuniga
//	Description:	A file that tests the BSTDepth class.  
//			
//************************************************************************
#include <iostream>
#include <stdlib.h>
#include "BSTDepth.h"

using namespace std;

int main( void )
{	
	BSTDepth<int> oneBSTDepth;
	
	for (int i=0; i<100; i++)
	{
		oneBSTDepth.myBST.insertItem(5*i+3);
	}
	
	cout << oneBSTDepth.computeDepth() << endl;
	oneBSTDepth.myBST.
	
	oneBSTDepth.myBST.~BSTree();
	
	for (int k=0; k<10; k++)
	{
		for (int j=0; j<200; j++)
		{	
			oneBSTDepth.myBST.insertItem(rand()%1000);
		}
	
		cout << oneBSTDepth.computeDepth()<< endl;
	
		oneBSTDepth.myBST.~BSTree();
	}
	
	return 0;
}