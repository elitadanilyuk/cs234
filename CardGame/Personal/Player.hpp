//
//  Player.hpp
//  CardGame
//
//  Created by Elita Danilyuk on 2/28/21.
//

#pragma once
#include <string>
using namespace std;

class Player{
public:
    Player();
    Player(string);
    string getPlayerName();
    static string playerName;

private:
};
