//************************************************************************
//
//	Assignment:		Exercise 4 
//	File:			main.cpp
//	Author:			Raul Zuniga
//	Due Date:		August 2, 2000
//
// 	Description: 	This program utilizes the Standard Template Library
//					(STL) to design and code a program to handle
//					linked list, stack_ll and queue_ll.
//	Requirements:	List:
//					1. Fill the list
//					2. Display the list
//					3. Insert by value
//					4. Display the list
//					5. Delete by value
//					6. Display the list
//		
//					Stack:
//					1. Fill the stack_ll
//					2. Display in the opposite order
//
//					Queue:
//					1. Fill the queue_ll
//					2. Display the queue_ll
//				
//************************************************************************
#include <fstream>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std; 					//introduces namespace std
int main( void )
{
	list<int> lst; 						//create an empty list
	stack<int> stck;					//create an empty stack_ll
	queue<int> que;						//create an empty queue_ll
	int i;
	
	ofstream fout( "stl.out");		 	//open file for output
	if (!fout) {fout << "Output file could not be opened" << endl; exit;}
		
	for (i=0; i<10; i++) 
	{
		lst.push_back(i);				//fill the list
		stck.push(i);					//fill the stack_ll
		que.push(i);					//fill the queue_ll
	}	
	
	list<int>::iterator p = lst.begin();//point to beginning of list
	list<int>::iterator location;
	
	fout << "List: \n";
	while(p != lst.end())
	{
		fout << *p;
		p++;
	}
	fout << "\n\n";
	
	//find the first location at which 5 can be inserted.
	location = lower_bound(lst.begin(), lst.end(),5);
	
	lst.insert(location, 1,5);			//insert by value
	
	p = lst.begin();			
	fout << "Insert a 5 by value: \n";	//display the list
	
	while(p != lst.end())
	{
		fout << *p;
		p++;
	}
	fout << "\n\n";
	
	lst.remove(5);						//remove by value
	
	p = lst.begin();					//display the list
	fout << "Delete a 5 by value: \n";
	
	while(p != lst.end())
	{
		fout << *p;
		p++;
	}
	fout << "\n\n";
	
	fout << "Stack in reverse order:\n";//display stack_ll in reverse order
	while(stck.size())
	{
		fout << stck.top();
		stck.pop();
	}
	fout << "\n\n";
	
	fout << "Queue:\n";					//display the queue_ll
	while(que.size())
	{
		fout << que.front();
		que.pop();
	}
	fout << "\n\n";
		
	fout.close();
	
	return 0;
}