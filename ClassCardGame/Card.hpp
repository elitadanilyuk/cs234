//
//  Card.hpp
//  CSC234 Class CardGame
//
//  Created by Elita Danilyuk on 2/28/21.
//

#pragma once

enum COLORS { RED, BLUE, GREEN, PURPLE, ORANGE, WILD};
const int WILDRANK = 100;

class Card {
public:
    void setColor(int);
    void setRank(int);
private:
    int color;
    int rank;
};
