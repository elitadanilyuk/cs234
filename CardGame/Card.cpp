//
//  Card.cpp
//  CardGame
//
//  Created by Elita Danilyuk on 2/28/21.
//

#include "Card.hpp"
#include <string>

Card::Card(){
    int i, colorNum = 1;
    for (i = 0; i < 52 - 2; i++) {
        for (int j = 1; j <= 10; j++) {
            
            deck[i] = to_string(j);
            
            switch (colorNum) {
                case 1:
                    deck[i] += "r";
                    break;
                case 2:
                    deck[i] += "b";
                    break;
                case 3:
                    deck[i] += "g";
                    break;
                case 4:
                    deck[i] += "p";
                    break;
                default:
                    deck[i] += "o";
                    break;
            }
            
            colorNum++;
        }
    }
    deck[i+1] = "WILD";
    deck[i+2] = "WILD";
}

// shuffle() will shuffle the contents of deck[]
// Pre: deck[] is an array with values in an incremental order
// Post: deck[] will be shuffled to a randomized order
void Card::shuffle(){
    for (int i = 0; i < 52 - 1; i++) {
        int randNum = i + (rand() % (52-i));
        swap(deck[i], deck[randNum]);
    }
};
