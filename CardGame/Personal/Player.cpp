//
//  Player.cpp
//  CardGame
//
//  Created by Elita Danilyuk on 2/28/21.
//

#include "Player.hpp"

Player::Player(){};

Player::Player(name){
    playerName = name;
};

string Player::getPlayerName(){
    return playerName;
}

