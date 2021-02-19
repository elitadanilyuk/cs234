//
//  main.cpp
//  ClassLab3.0
//
//  Created by Elita Danilyuk on 2/13/21.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;

//defining constant global values
const int DECK_SIZE = 52;
const int MAX_CARDS = 4;

int main(int argc, const char * argv[]) {
    //declaring & defining for main()
    int deck[52];
    int *ptr;
    ptr = deck;
    srand((unsigned int)time(NULL));
    
    //for() to define deck[]
    for (int i = 0; i < DECK_SIZE; i++) {
        *(ptr + i) = i;
    } //end for()
        
    //for() to select 4 random cards
    for (int j = 0; j < DECK_SIZE; j++) {
        *(ptr + j) = rand() % 51;
    } //end for()
    
    //for() to go through the 4 cards, find the suit and name/number, then print
    for (int i = 0; i < MAX_CARDS; i++) {
        //declaring & defining to find the cardName
        int cardNameNumber = *(ptr + i) % 13;
        string cardName;
        
        // if/elseif to find the correct name for the current card
        if (cardNameNumber == 0) {
            cardName = "Ace";
        }
        else if ((cardNameNumber == 1) || (cardNameNumber == 2) || (cardNameNumber == 3) ||
                 (cardNameNumber == 4) || (cardNameNumber == 5) || (cardNameNumber == 6) ||
                 (cardNameNumber == 7) || (cardNameNumber == 8) || (cardNameNumber)== 9){
            cardName = to_string(i+2);
        }
        else if (cardNameNumber == 10){
            cardName = "Jack";
        }
        else if (cardNameNumber == 11){
            cardName = "Queen";
        }
        else{
            cardName = "King";
        } //end if/elseif
        
        //declaring & defining for cardSuit
        int cardSuitNumber = *(ptr + i)/13;
        string cardSuit;
        
        // switch statement to set the Suit name for the current card
        switch (cardSuitNumber) {
            case 0:
                cardSuit = "Spades";
                break;
            case 1:
                cardSuit = "Hearts";
                break;
            case 2:
                cardSuit = "Diamonds";
                break;
            default:
                cardSuit = "Clubs";
                break;
        } // end switch(cardSuitNumber)
        
        printf("Card number %d is the %s of %s \n", *(ptr + i), cardName.c_str(), cardSuit.c_str());
    } //end for()
} //end main()
