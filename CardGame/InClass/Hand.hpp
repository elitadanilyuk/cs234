//
//  Hand.hpp
//  CSC234 Class CardGame
//
//  Created by Elita Danilyuk on 2/28/21.
//

#pragma once
#include <string>
#include <vector>
#include "Card.hpp"
#include "Hand.hpp"

using namespace std;

class Hand {
public:
    static const int CARDS_IN_HAND_COUNT = 10;

    Hand();
    Hand(Card[], int);
    Hand(Hand*, int);
    Hand(const Hand&);
    void sort();
    int discard();
    void score(string);
    void print();
    void setCard(int, Card);
    void operator =(const Hand&);
    int getHandScore();

    friend vector<int> validateGroup(const Hand*, string);
private:
    Card cards[CARDS_IN_HAND_COUNT];
    int handScore;
};
