//
//  CardGame.cpp
//  CardGame
//
//  Created by Elita Danilyuk on 2/19/21.
//

#include <iostream>
#include <string>
#include <ctime>
#include "Card.hpp"
#include "Player.hpp"
using namespace std;

//global variables
static const int MAX_PLAYERS = 4;
static const int MAX_CARDS = 52;

//// createCards() will define deck[]
//// Pre: deck[] will be initiallized to all 0's
//// Post: deck[] will have accurate cards in it
//void createCards(string deck[]){
//    int i, colorNum = 1;
//    for (i = 0; i < MAX_CARDS - 2; i++) {
//        for (int j = 1; j <= 10; j++) {
//
//            deck[i] = to_string(j);
//
//            switch (colorNum) {
//                case 1:
//                    deck[i] += "r";
//                    break;
//                case 2:
//                    deck[i] += "b";
//                    break;
//                case 3:
//                    deck[i] += "g";
//                    break;
//                case 4:
//                    deck[i] += "p";
//                    break;
//                default:
//                    deck[i] += "o";
//                    break;
//            }
//
//            colorNum++;
//        }
//    }
//    deck[i+1] = "WILD";
//    deck[i+2] = "WILD";
//}

//// shuffle() will shuffle the contents of deck[]
//// Pre: deck[] is an array with values in an incremental order
//// Post: deck[] will be shuffled to a randomized order
//void shuffle(string deck[]){
////    srand(time(0));
////
////    for(int i = 0; i < 52; i++){
////        int r = i + (rand() % (52 - i));
////
////        swap(deck[i], deck[r]);
////    }
//
//    for (int i = 0; i < MAX_CARDS - 1; i++) {
//        int randNum = i + (rand() % (52-i));
//        swap(deck[i], deck[randNum]);
//    }
//}

// deal() will deal the cards to players and return the hand dealt
// Pre: players will not have a hand dealt
// Post: players will have a hand dealt to them
string * deal(string hand[]){
    int nextCard += 1;
    if (nextCard <= 52) {
        return deck[nextCard - 1];
    }
    else{
        return -1;
    }
}

// draw() will add a card to a players hand
// Pre: n/a
// Post: player will have one additional card
void draw();

// discardCard() will take a players hand and discard a card and add the drawn card
// Pre: player has 10 specific cards
// Post: one of the 10 will be discarded and a new card will be stored
void discardCard();

// displayHand() will take a players hand[] and display it to them
// Pre: n/a
// Post: players will be displayed their current hand
string * displayHand(string hand[]){
    return 0;
}

// score() will look at a players hand and score it
// Pre: n/a
// Post: players hand will be scored
void score();

int main(int argc, const char * argv[]) {
//    srand(time(0));
//    string deck[MAX_CARDS];
//    shuffle(deck);
    
    Card deck;
    deck.shuffle();
    Player* player1 = new Player;
    Player* player2 = new Player;
    Player* player3 = new Player;
    Player* player4 = new Player;

    
    string players[MAX_PLAYERS];
    string hand[10];
    
    // get players names
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("Enter Player %d;", i);
        switch (i) {
            case 0:
                
                break;
                
            default:
                break;
        }
    }
    
    for (int i = 0; i < MAX_PLAYERS; i++) {
        for (int j = 0; j < 10; j++) {
//            deal(string *hand);
        }
    }
    
    /** do-while
     * players take turns:
     * draw() -> displayHand() -> discardCard()
     */
    
    score();
    
    // output the player who won
    
    // ask players if they would like to play again (have a larger do-while loop for this)
    
} //end main()
