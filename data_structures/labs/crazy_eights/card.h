// File Name: card.h
//
// Author: Jill Seaman
//    Modified from a program written by Owen Astrachan and Roger Priebe
//
// This class represents a playing card, i.e., "ace of spades"
// A Card is constructed from a rank (integer in range 1..13)
// and a suit (Card::spades, Card::hearts, Card::diamonds, Card::clubs)
//
// Note that the Ace is represented by 1 and the King by 13

#ifndef CARD_H
#define	CARD_H

#include <iostream>
#include <string>
using namespace std;

class Card
{
  public:

    enum Suit {spades, hearts, diamonds, clubs};
    
    Card();                     // default: ace of spades

    Card(int, Suit);

    string toString()   const;  // return string version: Ac 4h Js
    int   getRank()     const;  // return rank, 1..13
    Suit  getSuit()     const;  // return suit
    
    bool operator == (const Card &rhs) const;
    
  private:

    int rank;                   // numeric value of the card
    Suit suit;                  // the suit of the card

    string suitString()  const;  // return "s", "h",...
    string rankString()  const;  // return "A", "2", ..."Q"
    
};
#endif	/* CARD_H */

