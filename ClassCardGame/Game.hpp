//
//  Game.hpp
//  CSC234 Class CardGame
//
//  Created by Elita Danilyuk on 2/28/21.
//

#pragma once
#include "Deck.hpp"
#include "Player.hpp"

class Game {
public:
    typedef Player* PLAYERPTR;

    void start(PLAYERPTR*, size_t);
    Deck* getPlayingDeck();

private:
    Deck *playingDeck;
};
