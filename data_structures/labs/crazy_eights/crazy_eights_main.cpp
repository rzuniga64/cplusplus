
// File Name: card_demo.cpp
//
// Author: Jill Seaman
// Date: 7/3/2013
// Assignment Number: 1
// CS3358 Spring 2015
// Instructor: Jill Seaman
//
// This is a small demonstration program showing how the Player and Deck
// classes are used.

#include <iostream>  
#include "card.h"
#include "deck.h"
#include "player.h"

using namespace std;

//***********************************************************
// dealHand: deals a specified number of cards from the deck
//           into a player's hand.
// d: the Deck of Cards
// p: the Player
// numCards: the number of cards to deal
//***********************************************************
void dealHand(Deck &deck, Player &p, int numCards){
    for (int i=0; i < numCards; i++)
        p.addCard(deck.dealCard());
}

void play(Player &p, Card &discardPileCard, Deck &deck) {
    int wildcard = 8;   // an eight of any suit is a wildcard
    int sizeOfHand = p.getHandSize();
    bool hasPlayerDiscarded = false;
    do {
        if (discardPileCard.getRank()== wildcard &&\
            p.hasCardWithSuit(discardPileCard.getSuit(), discardPileCard))
        	hasPlayerDiscarded = p.removeCardFromHand(discardPileCard);
        else if (p.hasCardWithRank(discardPileCard.getRank(), discardPileCard))
        	hasPlayerDiscarded = p.removeCardFromHand(discardPileCard);
        else if (p.hasCardWithSuit(discardPileCard.getSuit(), discardPileCard))
        	hasPlayerDiscarded = p.removeCardFromHand(discardPileCard);
        else if (p.hasCardWithRank(wildcard, discardPileCard))
        	hasPlayerDiscarded = p.removeCardFromHand(discardPileCard);

        if (!hasPlayerDiscarded)
        	p.addCard(deck.dealCard());


        cout << p.getName() <<" has : " << p.showHand() << endl;
    
    } while(!hasPlayerDiscarded && deck.size() > 0);
}

int main( )
{
    int numCards = 7;    // size of a hand
    bool isPlayer2Turn = false;
    
  
    Player p1("Joe");    // player 1
    Player p2("Jane");   // player 2
    
    // create a deck of cards (shuffled).
    Deck deck;

    // deal out cards to each player
    dealHand(deck, p1, numCards);
    dealHand(deck, p2, numCards);

    //show hands of each player
    cout << p1.getName() <<" has : " << p1.showHand() << endl; 
    cout << p2.getName() <<" has : " << p2.showHand() << endl << endl;
    

    //turn over the top card of the deck
    Card discardPileCard = deck.dealCard();
    cout << "The discard pile contains: " << discardPileCard.toString() << endl;
 
    do {
        if (isPlayer2Turn) {
          play(p2, discardPileCard, deck);
          isPlayer2Turn = false;
        } else {
          play(p1, discardPileCard, deck);
          isPlayer2Turn = true;
        }
    } while (deck.size() > 0 && p1.getHandSize() > 0 && p2.getHandSize() > 0);
    
    if (p1.getHandSize() == 0 )
        cout << p1.getName() << " is the winner." << endl;
    else if (p2.getHandSize() == 0)
        cout << p2.getName() << " is the winner." << endl;
    else if (deck.size() == 0)
        cout << "The deck has " << deck.size() << " cards so the game is a draw" << endl;
   
    return 0;
}








