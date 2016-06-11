// File Name: card.cpp
//
// Author: Raul Zuniga
// Date: 2/3/2015
// Assignment Number: 1
// CS3358 Spring 2015
// Instructor: Jill Seaman
//
// Definition file for the Card class

#include <stdlib.h>
#include <string>
#include "card.h"

using namespace std;

//***********************************************************
//  Card():   Create a card based whose rank is 1 and suit is
//          spades.
// **********************************************************
Card::Card()
{
    rank = 1;
    suit = spades;
}

//***********************************************************
//  Card(int, Suit):   
//  Pre:    1 <= rank <= 13, suit is spades, clubs, diamonds,
//			or hearts.
//  Post:   Create a card based on a given rank (1..13) and
//			suit (spades, hearts, diamonds, clubs).
// **********************************************************
Card::Card(int rank, Suit suit) 
{
    if ((rank >=1 && rank<=13) || (suit <=0 && suit >=3)){
        this->rank = rank;
        this->suit = suit;
    } else {
        cout << "The rank or suit is out of range." << endl;
        cout << "Rank: " << getRank();
        cout << "Suit: " << getSuit();
    }
}

//***********************************************************
//  suitString():  
//  Pre:    the suit of the card (spades, hearts, diamonds, 
//          clubs)
//  Post:   returns the suit of the card as a string:
//          "s", "h","d", or "c"
//***********************************************************
string Card::suitString()  const 
{
    string theSuit;
    theSuit.clear();
    switch(suit)
    {
        case spades:
            theSuit = "s";
            break;
        case hearts:
            theSuit = "h";
            break;
        case diamonds:
            theSuit = "d";
            break;
        case clubs:
            theSuit = "c";
            break;
        default:
            theSuit = " ";
    }
    return theSuit;
}

//***********************************************************
//  rankString():  
//  Pre:    the rank of the card (1-13)
//  Post:   returns a card rank as  a string:
//          "A", "2", ..."J", "Q", "K"
//***********************************************************
string Card::rankString()  const 
{
    string theRank;
    theRank.clear();
    switch(rank) 
    {
        case 1:
            theRank = "A";
            break;
        case 2:
             theRank = "2";           
             break;
        case 3:
             theRank = "3";        
             break;
        case 4:
            theRank = "4";          
             break;            
        case 5:
            theRank = "5";            
             break;            
        case 6:
            theRank = "6";           
              break;           
        case 7:
             theRank = "7";           
             break;            
        case 8:
             theRank = "8";           
             break;            
        case 9:
             theRank = "9";          
             break;            
        case 10:
             theRank = "10";           
             break;            
        case 11:
            theRank = "J";         
             break;            
        case 12:
             theRank = "Q";           
             break;            
        case 13:
             theRank = "K";          
             break; 
        default:
            theRank = " ";
    }
    return theRank;
}

//***********************************************************
//  toString():  
//  Pre:    the rank of the card (1-13) and suit 
//          (spades, hearts, diamonds, clubs)
//  Post:   returns a card rank and suit as a string: 
//          "Ac", "2h"
//***********************************************************
string Card::toString() const 
{
    if (rankString() !=" " && suitString() != " ") 
        return rankString()+suitString();
}

//***********************************************************
//  getRank():  
//  Pre:    none
//  Post:   returns the rank of the card as "A", "2", ...K"
//***********************************************************
int Card::getRank() const 
{
    return rank;
}

//***********************************************************
//  getSuit():  
//  Pre:    none
//  Post:   returns the suit of the card -
//          (spades, hearts, diamonds, clubs)
//***********************************************************
Card::Suit Card::getSuit() const 
{
    return suit;
}

//***********************************************************
//  operator=:  
//  Pre:    two valid cards
//  Post:   returns true of the Card objects are equal, 
//          else false.
//***********************************************************
bool Card::operator ==(const Card& rhs) const 
{
    return (this->rank == rhs.rank || this->suit == rhs.suit);
}
