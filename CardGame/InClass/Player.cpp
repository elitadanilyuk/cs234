//
//  Player.cpp
//  CSC234 Class CardGame
//
//  Created by Elita Danilyuk on 2/28/21.
//

#include <string>
#include "Player.hpp"

Player::Player() {
    score = 0;
    name = "NONAME";
    playingHand = (Hand*)NULL;
};

Player::Player(string s) {
    name = s;
};

string Player::getName() const {
    return name;
}

string Player::toString() const {
    return name + " has score of " + to_string(totalScore);
}

void Player::scoreHand(){
    totalScore += playingHand->score();
}

void Player::setPlayingHnad(Deck* gameDec){
    playingHand = gameDeck->deal();
}

void Player::setPlayingHand(Card newCard){
    playingHand->setCard(playingHand->discard(), newCard);
}

Hand *Player::getPlayingHand(){
    return playingHand;
}
