//
//  main.cpp
//  CSC234 Class CardGame
//
//  Created by Elita Danilyuk on 2/28/21.
//

#include <iostream>
#include "Game.hpp"
#include "Deck.hpp"
#include "Player.hpp"

using namespace std;

typedef Player*  PLAYERPTR;

int main() {

    int numberOfPlayers;
    Game myGame;
    char replay;
    PLAYERPTR *gamePlayers;
    string playerName;

    //game loop
    do{
        //create CardGame object & initialize it with deck of cards

        // determine number of players
        cin >> numberOfPlayers;

        //dynamic allocation of array of pointers
        gamePlayers = new PLAYERPTR[numberOfPlayers];

        //construct player objects
        for (int i = 0; i < numberOfPlayers; i++) {
            printf("Please enter player #%d name:", i);
            cin >> playerName;
            gamePlayers[i] = new Player(playerName);
        }

        //launch card game
        myGame.start(gamePlayers, numberOfPlayers);

        cout << "Would you like to play again (y/n)? ";
        cin >> replay;

    }while (replay == 'y');
    
}
