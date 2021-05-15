//
//  Deck.hpp
//  CSC234 Class CardGame
//
//  Created by Elita Danilyuk on 2/28/21.
//

#pragma once
#include "Card.hpp"
#include "Hand.hpp"

class Deck {
public:
    static const int NUMCARDS = 11;
    static const int NUMCOLORS = 5;

    Deck();
    Hand *deal();
    Card draw();
private:
    void shuffle();
    Card cards[NUMCOLORS][NUMCARDS];
    Card* topOfDeck;
    int count;
};
