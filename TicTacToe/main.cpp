//
//  main.cpp
//  CSC234 TicTacToe
//
//  Created by Elita Danilyuk on 3/26/21.
//

#include <iostream>
#include <cstddef>
#include <string>

using namespace std;

typedef int* IntPtr;
typedef char* CharPtr;

// Precondition: board has not been printed
// Postcondition: board is printed
void static printBoard(char m[][3]){
    // Printing the header of the board
    for (int i = 1; i < 3+1; i++) {
        printf(" :  %d ", i);
    }
    printf(" :\n--------------------\n");

    // Printing the rest of the formated board
    for (int i = 0; i < 3; i++) {
        printf("%d: ", i+1);
        for (int j = 0; j < 3; j++){
            printf(" %c ", m[i][j]);
            printf(" : ");
        }
        cout << endl;
        printf("--------------------\n");
    }
    cout << endl;
} //end printBoard()

// Precondition: game is still playing, board has been allocated
// Postcondition: board is unaltered, returns a bool if the game is over
bool checkForWinner(string currPlayer, char board[][3], bool gameOver){
    // for() to check the rows
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board [i][1]) &&
            (board[i][0] == board[i][2]) &&
            (board[i][0] != '.')) {
            gameOver = true;
        }
    }
    
    // for() to check the columns
    for (int i = 0; i < 3; i++) {
        if ((board[0][i] == board [1][i]) &&
            (board[0][i] == board[2][i]) &&
            (board[0][i] != '.')) {
            gameOver = true;
        }
    }
    
    // if statement to check the first diagonal
    if((board[0][0]==board[1][1]) &&
       (board[1][1]==board[2][2]) &&
       (board[0][0] != '.')){
        gameOver = true;
    }

    // if statement to check the second diagonal
    if((board[0][2]==board[1][1]) &&
       (board[1][1]==board[2][0]) &&
       (board[0][2] != '.')){
        gameOver = true;
    }
    
    // if statement to return the winner if the game is over
    if (gameOver == true) {
        cout << currPlayer << " wins!\n\n";
    }

    return gameOver;
} //end checkForWinner()

// Precondition: game is still playing, no winner, board has been allocated
// Postcondition: board is unaltered, returns a bool is the game is a draw and over
bool checkForDraw(char board[][3], bool gameOver){
    int x = 1, count = 0;
    
    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '.') {
                count++;
            }
            x++;
        }
    }
    
    if (count < 1) {
        cout << "It's a draw!\n\n";
        gameOver = true;
    }
    
    return gameOver;
}

int main()
{
    int numRows = 3, numCols = 3;
    char board[3][3];
    string player1, player2;
    char player1Char = 'X', player2Char = 'O';
    char currTurn = 'X';
    char playAgain;
    bool continuePlaying = true, gameOver = false;
    
    // do-while to continuePlaying until the players say otherwise
    do{
        cout << "\nPlease enter the name of player 1: ";
        cin >> player1;

        cout << player1 << " will be symbol " << player1Char << "\n\n" << "Please enter the name of player 2: ";
        cin >> player2;
        
        cout << player2 << " will be symbol " << player2Char << "\n\n";

        // setting the board then printing it
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
                board[i][j] = '.';
        }
        printBoard(board);
        
        // do-while to continuePlaying until there is a winner or draw
        do {
            // if-else to get the correct players turn
            if (currTurn == 'X') {
                cout << player1 << "'s Turn!\nEnter the row number: ";
                cin >> numRows;
                
                cout << "Enter the column number: ";
                cin >> numCols;
            } else {
                cout << player2 << "'s Turn!\nEnter the row number: ";
                cin >> numRows;
                
                cout << "Enter the column number: ";
                cin >> numCols;
            }
                    
            // if-else to validate players choice for their turn
            // if valid: it will output the updated board and change to the next player
            if (board[numRows-1][numCols-1] == '.') {
                //setting the correct element to the correct player's symbol
                board[numRows-1][numCols-1] = currTurn;
                cout << endl;
                printBoard(board);
                
                // if-else switching to the next player
                if (currTurn == 'X') {
                    currTurn = 'O';
                } else{
                    currTurn = 'X';
                }
            } else{
                cout << "Invalid slot! Try again!\n";
            }
            
            // if-else to check for the correct winner
            if (currTurn == 'X') {
                gameOver = checkForWinner(player2, board, gameOver);
            } else {
                gameOver = checkForWinner(player1, board, gameOver);
            }
            // if gameOver is still false: check for a draw
            gameOver = checkForDraw(board, gameOver);

        } while (!gameOver);
                
        // do-while to make sure input isValid
        bool isInvalid = true;
        do {
            cout << "Would you like to play again y/n? ";
            cin >> playAgain;
            
            // if-elseif players would like to continuePlaying
            if ((playAgain == 'y') || (playAgain == 'Y')) {
                continuePlaying = true;
                gameOver = false;
                currTurn = 'X';
                isInvalid = false;
            }
            else if ((playAgain == 'n') || (playAgain == 'N')){
                continuePlaying = false;
                isInvalid = false;
            }
            else{
                cout << "Invalid option.\n\n";
                isInvalid = true;
            }
        } while (isInvalid);
        
    } while (continuePlaying);

    return 0;
} //end Main()
