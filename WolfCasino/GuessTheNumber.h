//
//  GuessTheNumber.h
//  CSC234 GuessTheNumber
//
//  Created by Elita Danilyuk on 4/11/21.
//

#include <string>
#include "Casino.h"
#pragma once

using namespace std;

namespace CSC234{

    const int MIN_VALUE_ALLOWED = 10;
    const int MAX_VALUE_ALLOWED = 1000;
        
    class GuessTheNumber : public Casino{
    public:
        //Constructor
        GuessTheNumber();

        //Making and returning a new GuessTheNumber game
        static GuessTheNumber* makeGame();

        void start(); //This plays the game

    private:
        void run(); //This runs the game

        //This sets a random number that the user needs to guess
        int static setRndNumber(int& rndNum, int maxBound);

        //This returns a bool if the users input for a maxBound is valid
        bool static isValidBound(const int userInput);

        //This returns a bool if the users guess is a valid guess
        bool static isValidGuess(const int& guess, const int& maxBound);

        //This returns a bool if the user would like to quit
        bool static areYouAQuiter(const int guess, const int maxBound);

    }; //end class GuessTheNumber

} //end namespace CSC234