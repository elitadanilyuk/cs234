//
//  Deck.cpp
//  CSC234 Class CardGame
//
//  Created by Elita Danilyuk on 2/28/21.
//

#include "Deck.hpp"

Deck::Deck(){
    int i, j;
    for (i = 1; i < 6; i++) {
        for (j = 1; j < 11; j++) {
            cards[i][j].setColor(i);
            cards[i][j].setRank(j);
        }
        wildCards[0].setColor(WILD);
        wildCards[0].setRank(WILDRANK);
        wildCards[1].setColor(WILD);
        wildCards[1].setRank(WILDRANK);
        topOfDeck = &cards[0][0];
    }
};

Hand* Deck::deal(){
    Card cards[Hand::CARDS_IN_HAND];
    
    for (int i = 0; i < Hand::CARDS_IN_HAND; i++) {
        cards[i] = draw();
    }
    
    Hand* newHand = new Hand(cards, Hand::CARDS_IN_HAND);
    return newHand;
}

Card Deck::draw(){
    Card drawnCard = *topOfDeck;
    
    topOfDeck->setColor(Card::DELT);
    topOfDeck->setRank(Card::DELT);
    
    count --;
    shuffle();
    return drawnCard;
}

void shuffle(){
    int randNum = rand();
    
    if(count > 0){
        while(cards[(randNum % NUMCOLORS)][randNum % NUMCARDS].getColor() == Card::DELT){
            randNum = rand();
        }
    }else{
        topOfDeck = NULL;
    }
}
