//
//  GuessTheNumber.cpp
//  CSC234 GuessTheNumber game
//
//  Created by Elita Danilyuk on 4/11/21.
//

#include "GuessTheNumber.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

namespace CSC234{

    //Constructor
    GuessTheNumber::GuessTheNumber(){}

    /**
     * Precondition: The GuessTheNumber game has not been created.
     * Postcondition: A new GuessTheNumber game is created and returned.
     * 
     * @return new *GuessTheNumber
     */
    GuessTheNumber* GuessTheNumber::makeGame(){
        return new GuessTheNumber;
    } //end makeGame()

    /**
     * Precondition: A GuessTheNumber game has been created, but has not yet started.
     * Postcondition: The GuessTheNumber game has started and has began to run().
     */
    void GuessTheNumber::start() {
        run();
    } //end GuessTheNumber()

    /**
     * Precondition: The GuessTheNumber game has been created and started.
     *      @see GuessTheNumber::makeGame() && GuessTheNumber::start()
     * Postcondition: The GuessTheNumber game has been run and completed.
     */
    void GuessTheNumber::run(){
        int maxBound, guess, tries, rndNum = 0;
        bool continuePlaying = true;
        char playAgain;

        cout << "Guess The Number\n\n";

        do //do-while continuePlaying is true
        {
            do //do-while input maxbound isValidBound
            {
                printf("Enter a maximum bound between %d and %d: ", MIN_VALUE_ALLOWED, MAX_VALUE_ALLOWED);
                cin >> maxBound;
                
            } while (isValidBound(maxBound));

            rndNum = setRndNumber(rndNum, maxBound);

            do //do-while (user guess != computed rndNum) OR while (the user is not a quitter)
            {
                do //do-while the user guess is a valid value
                {
                    printf("If you'd like to quit like a loser enter any value outside of 0 and &d.\nOtherwise, enter a guess between 0 and %d.): ", maxBound, maxBound);
                    cin >> guess;
                } while (isValidGuess(guess, maxBound));
                
                if (areYouAQuiter(guess, maxBound))
                {
                    cout << "Lame... I knew you were a quiter.";
                } else {
                    tries++;

                    if(guess > rndNum){
                        cout << "\nYour guess is too high! Try again!\n";
                    }
                    else if(guess < rndNum){
                        cout << "\nYour guess is too low! Try again!\n";
                    }
                    else{
                        printf("\nYOU GUESSED IT!\n\nIt only took you %d guesses!\n", tries);
                    }
                } //end if-else user is a loser
            } while ((guess != rndNum) && (!areYouAQuiter(guess, maxBound)));

            bool isInvalidVal = true;
            do //do-while to make sure input isValid
            {
                cout << "Would you like to play again y/n? ";
                cin >> playAgain;

                // if-elseif players would like to continuePlaying
                if ((playAgain == 'y') || (playAgain == 'Y')) {
                    continuePlaying = true;
                    isInvalidVal = false;
                }
                else if ((playAgain == 'n') || (playAgain == 'N')){
                    continuePlaying = false;
                    isInvalidVal = false;
                }
                else{
                    cout << "Invalid option.\n\n";
                    isInvalidVal = true;
                }
            } while (isInvalidVal);

        } while (continuePlaying);
    } //end run()

    /**
     * Precondition: The maxBound has already been initialized and declared.
     *      The rndNumber has been initialized but not yet declared.
     * Postcondition: The rndNumber has been declared and returned. @see GuessTheNumber::run()
     * 
     * @param int& rndNumber: a random number the user will need to guess
     * @param int& maxBound: a maxBound that will be used to limit the random number value
     * @return int rndNumber: returns a declared random number between 0-maxBound
     */
    int GuessTheNumber::setRndNumber(int& rndNumber, int maxBound){
        srand(time(0));
        rndNumber = rand() % maxBound + 0;
        return rndNumber;
    } //end setRndNumber()

    /**
     * Precondition: The userInput is entered to set a maxBound, which has not yet been validated.
     * Postcondition: The userInput has been validated.
     * This returns a true or false if the userInput is in fact a valid bound.
     * 
     * @param int userInput: the users input to set the maxBound
     * @return bool true if the userInput is between 10-1,000
     */
    bool GuessTheNumber::isValidBound(const int userInput){

        bool isValidBound;

        //make sure: 10 >= userInput <= 1,000
        if((userInput >= MIN_VALUE_ALLOWED) || (userInput <= MAX_VALUE_ALLOWED)){
            isValidBound = true;
        } else {
            isValidBound = false;
        }

        return isValidBound;

    } //end isValidBound()

    /**
     * Precondition: The user has entered a guess.
     * Postcondition: The users guess has been validated.
     * This returns true or false if the users guess is in fact a valid guess.
     * 
     * @param const int& guess: the users guess
     * @param const int& maxBound: the maxBound (established previously by the user)
     * @return bool true if the guess is between 0 and the maxBound, or false otherwise
     */
    bool GuessTheNumber::isValidGuess(const int& guess, const int& maxBound){
        //if-else to determine if the user's guess is a valid guess
        if ((guess <= maxBound && guess >= 0) || areYouAQuiter(guess, maxBound))
        {
            //users guess is valid
            return true;
        } else {
            //users guess is invalid
            cout << "You entered an invaid guess.\n";
            return false;
        }
    } //end isValidGuess()

    /**
     * Precondition: The user has entered a guess and it has been validated.
     *      @see GuessTheNumber::isValidBound()
     * Postcondition: If the user is a quiter, this will end the current round of the game.
     * 
     * @param const int guess: the users guess/input
     * @param const int maxBound: the maximum int bound
     * @return bool true if the guess/input it out of bounds to quit, or false otherwise
     */
    bool GuessTheNumber::areYouAQuiter(const int guess, const int maxBound){
        if (guess <= maxBound && guess >= 0)
        {
            return false;
        } else {
            return true;
        } 
    } //end areYouAQuiter()

} //end namespace CSC234