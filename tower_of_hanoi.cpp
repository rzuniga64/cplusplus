//************************************************************************
//
//	Assignment:		Lab 1
//	File:			Tower_of_Hanoi.cpp
//	Author:			Raul Zuniga
//	Due Date:		February 1, 2000
//	Description:	This program will move a user-specified number of
//					disks from pin 1 to pin 3 using pin 2 as a spare.
//
//************************************************************************
#include <iostream>

using namespace std; 	//introduces namespace std

void move(int n, char start, char target, char temp);

int main()
{
    int number;

    cout << "Enter the number of disks: ";
    cin >> number;
    move(number,'A','C','B');
    return 0;
}

void move(int n,char start, char target, char temp)
{
    if (n==1){cout<<"Move from " << start << " to " << target << "\n";}
    else
    {
        move(n-1,start,temp,target);
        move(1,start,target,temp);
        move(n-1,temp,target,start);
    }
}