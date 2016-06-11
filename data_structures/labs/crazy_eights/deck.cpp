// File Name: deck.cpp
//
// Author: Raul Zuniga
// Definition file for the Card class

#include <iostream>
#include <string>
#include <cstdlib> // For rand and srand
#include <ctime> // For the time function
#include "card.h"
#include "deck.h"

using namespace std;

//***********************************************************
//  Card(): Create pristine, shuffled deck of cards 
//          (cards in random order)  
// **********************************************************
Deck::Deck()            
{
    index = 0;
    
    Card::Suit suits[4] = {Card::spades, Card::hearts, Card::diamonds, Card::clubs};
    
    for (int i=1; i < 14; i++){
        for (int j=0; j < 4; j++){
            Card card = Card(i,suits[j]);
            cards[index] = card;
            if (index < 51)
                index++;
        }
    }
   
    // Seed the random number generator, so it uses a different
    // sequence of numbers every time program is run
    unsigned seed = time(0);    // Get the current system time
    srand(seed);                // Seed the random generator
    int randomPosition;         // A random number between 0 and 51
    
    // randomly shuffle the deck
    for (int j=0; j < SIZE; j++) {
        randomPosition = rand() % SIZE;
        Card temp = cards[0];
        cards[0] = cards [randomPosition];
        cards[randomPosition] = temp;     
    }
}

//***********************************************************
//  dealCard():  
//  Pre:    A deck of cards
//  Post:   returns a card.  If 52 cards are dealt, fail.
//***********************************************************
Card Deck::dealCard()  
{
    Card topcard;
    if (index >= 0) {
        topcard = cards[index];
        index--;
        return topcard;
    }
}

//***********************************************************
//  size():  
//  Pre:    A deck of cards.
//  Post:   returns the number of cards left in the deck.
//***********************************************************
int Deck::size() const  
{
    return index;
}

void Deck::display() const  
{
    for (int i=0; i < size()+1; i++)
        cout << cards[i].toString() << " ";
    cout << endl;

}

