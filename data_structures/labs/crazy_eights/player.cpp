// File Name: player.cpp
//
// Author: Raul Zuniga
// Definition file for the Player class

#include <iostream>
#include <string>
#include "player.h"

using namespace std;

//***********************************************************
//  showHand():  
//  Pre:    none
//  Post:   returns the hand as a string
//***********************************************************
Player::Player() 
{
    name = "Joe";
}

//***********************************************************
//  showHand():  
//  Pre:    none
//  Post:   returns the hand as a string
//***********************************************************
string Player::showHand() const
{
    string theHand = "";
    for (int i=0; i < getHandSize(); i++)
        theHand += hand[i].toString() + " ";
    
    return theHand;
}
    
//***********************************************************
//  getHandSize():  
//  Pre:    none
//  Post:   returns the number of cards in the hand
//***********************************************************
int Player::getHandSize() const
{
    return hand.size();
}

//***********************************************************
//  addCard(Card c):  
//  Pre:    the top card from the deck
//  Post:   adds a card to the hand
//***********************************************************
void Player::addCard(Card c)    //adds a card to the hand
{
    hand.push_back(c);
}
    
//***********************************************************
//  removeCardFromHand(Card c):  
//  Pre:    none
//  Post:   Remove a card c from the hand and return true 
//          if successful
//***********************************************************
bool Player::removeCardFromHand(Card c)
{
    int pos = -1;    // position of Card c if found in hand
    int wildcard = 8;// an eight of any suit is a wildcard
    bool isRemoved = false; 
    Card temp;       // swaps the Card c if found with last card in hand
    
    // find card in hand that  is equal to Card c or that is a wildcard.
    if (c.getRank()== wildcard) {
        for (int i=0; i < hand.size() && pos < 0; i++) {
            if (hand[i].getSuit() == c.getSuit() || hand[i].getRank() == wildcard)
                pos = i;
        }
    } else {
        for (int i=0; i < hand.size() && pos < 0; i++) {
            if (hand[i] == c)
                pos = i;
        }
    }
     

    cout << this->getName() << " plays a " << hand[pos].toString() << endl;

    
    // move the matching card to the end of hand and pop it to remove it
    if (pos >= 0) {
        temp = hand[hand.size()-1];
        hand[hand.size()-1] = hand[pos];    
        hand[pos] = temp;
        hand.pop_back();        
        isRemoved = true;
    }
        
    return isRemoved;
}

//***********************************************************
//  hasCardWithRank(int r, Card &c1):  
//  Pre:    
//  Post:   Determines if the player has a card with the 
//          given rank. e.g. a call to a player with a 7d 
//          would return true and set c1 to 7d if passed a 7 
//          as a parameter.  Otherwise returns false
//***********************************************************
bool Player::hasCardWithRank(int r, Card &c1)
{
    bool isTrue = false;
    for (int i=0; i < hand.size(); i++) {
        if (hand[i].getRank() != 8 && hand[i].getRank() == r) {
            c1 = hand[i];
            isTrue = true;
            break;
        } else if (hand[i].getRank() == 8) {
            c1 = hand[i];
            isTrue = true;
        }
    }
    return isTrue;
}

//***********************************************************
//  hasCardWithSuit(Card::Suit s, Card &c1)  
//  Pre:    
//  Post:   Determines if the player has a card with the 
//          given Suit. e.g. a call to a player with a 7d 
//          would return true and set c1 to 7d if passed a 
//          'd' as a parameter.  Otherwise returns false
//***********************************************************
bool Player::hasCardWithSuit(Card::Suit s, Card &c1)
{
    bool isTrue = false;
    for (int i=0; i < hand.size(); i++) {
        if (hand[i].getRank() != 8 && hand[i].getSuit() == s) {
            c1 = hand[i];
            isTrue = true;
            break;
        }
    }
    return isTrue;
}
