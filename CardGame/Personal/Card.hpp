//
//  Card.hpp
//  CardGame
//
//  Created by Elita Danilyuk on 2/28/21.
//

#pragma once
#include <string>
using namespace std;

class Card{
public:
    Card();
    void shuffle();

private:
    string deck[52];
};
