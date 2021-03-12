//
//  Player.hpp
//  CSC234 Class CardGame
//
//  Created by Elita Danilyuk on 2/28/21.
//

#pragma once
#include <string>
#include "Hand.hpp"
#include "Deck.hpp"

using namespace std;

class Player {
public:
    Player(string);
    ~Player();
    string getName() const;
    string toString() const;
    void setPlayingHand(Deck *);
    void setPlayingHand(Card);
    Hand *getPlayingHand();
    int getTotalScore() const;
    void scoreHand();
private:
    int totalScore;
    string name;
    Hand *playingHand;
};
