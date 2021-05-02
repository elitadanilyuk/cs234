#include <iostream>
#include <string>
#include "Casino.h"
#include "TicTacToeGame.h"
#include "Yahtzee.h"
#include "ColoradoTrail.h"
//#include "CardsAgainstHumanity.h"
#include "SpaceDogs.h"
#include "Nibbles.h" // Dan
#include "BlackJack.h" // Zach Keeler
#include "GuessTheNumber.h" // Elita


namespace CSC234 {
	//class Casino implementation file
	void Casino::play(string gameName) {
		Casino* game = NULL;   //pointer can refer to object of subclass

		if (gameName == "TicTacToeGame")
			game = TicTacToeGame::makeGame();

		if (gameName == "Yatzee")
			game = Yahtzee::makeGame();

		if (gameName == "The Colorado Trail")
			game = ColoradoTrail::makeGame();

	/*	if (gameName == "Cards Against Humanity")
			game = CardsAgainstHumanity::makeGame();*/

		if (gameName == "SpaceDogs")
			game = SpaceTrader::makeGame();

		if (gameName == "Nibbles")
			game = Nibbles::makeGame();

		if (gameName == "BlackJack") {
			game = BlackJack::makeGame();
		}

		if (gameName == "GuessTheNumber")
			game = GuessTheNumber::makeGame();

		game->start();  // using late binding, invoke game start
		delete game;	// cleaning up heap

	}

	void Casino::start() {
		std::cout << "Subclass funtion start() is not defined." << endl;
	}

	Casino::~Casino() {
		std::cout << "Casino desctructor here" << endl;
	}
}
