//
//  Card.cpp
//  CSC234 Class CardGame
//
//  Created by Elita Danilyuk on 2/28/21.
//

#include "Card.hpp"

void Card::setColor(int c){
    switch (c) {
        case 0:
            color = RED;
            break;
        case 1:
            color = BLUE;
            break;
        case 2:
            color = GREEN;
            break;
        case 3:
            color = PURPLE;
            break;
        case 4:
            color = ORANGE;
            break;
        default:
            color = WILD;
            break;
    }
}

void Card::setRank(int r){
    switch (r) {
        case 0:
            rank = r+1;
            break;
        case 1:
            rank = r+1;
            break;
        case 2:
            rank = r+1;
        default:
            rank = WILDRANK;
            break;
    }
}
