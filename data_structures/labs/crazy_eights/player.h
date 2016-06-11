// File Name: player.h
//
// Author: Jill Seaman
//    Modified from a program written by Roger Priebe
// CS3358 Spring 2015
// 
// This class represents a player in a card game.
// The hand is the player's set of cards to play with.

#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>
#include <string>
#include <vector>

#include "card.h"
using namespace std;

class Player
{
  public:
    Player();
    
    Player(string n) {
        name = n;
    }

    string getName() const {
       return name;
    }
    
    string showHand() const;
    int getHandSize() const;
    void addCard(Card c);              //adds a card to the hand
    
    //Remove the card c from the hand and return true if successful
    bool removeCardFromHand(Card c);
    
    //Does the player have a card with the given rank in her hand?
    //e.g. a call to a player with a 7d would return true and set c1 to 7d 
    //  if passed a 7 as a parameter.  Otherwise returns false
    bool hasCardWithRank(int r, Card &c1);
    
    //Does the player have a card with the given Suit in her hand?
    //Similar to hasCardWithSuit
    bool hasCardWithSuit(Card::Suit s, Card &c1);
        
  private:
    vector <Card> hand;  // VECTOR
    string name;
};

#endif	/* PLAYER_H */

