/*
	TIC-TAC-TOE CPP
	I was bored, so made a TIC-TAC-TOE game using my knowledge of CPP.
	This version prints a nice clean board every time.
	My title sucks... but it was a quick project.
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
//My UNIVERSAL library to check OS system commands
#include "GTAWWEKID.h"

using namespace std;

//Just seperate method to check if player won
bool checkBoard(char board[3][3], char player);
int main()
{
	//run loop
	bool inGame = true;
	//Count turns, even = x; odd = y;
	int turn = 1;
	//selection loop
	bool findPlace;
	//selections
	int column;
	int row;
	//buffer
	string buffer;
	//winning player
	char winner = '-';
	//current player
	char player;
	//empty game board
	char board[3][3] = {
	{' ', ' ', ' '},
	{' ', ' ', ' '},
	{' ', ' ', ' '}
	};
	//Dumb instructions
	string title = "\tTIC-TAC-TOE;\nHow to play: It's just like the tic-tac-toe at home. The objective is to get 3 in a row; up-and-down, side-to-side-, or corner-to-corner. In this version, you will be prompted for a top number, and then a row number. Your piece will then be set, and the next person will go. \n\n\n";


	//Create a loop to run game
	do{
	//Clear OUTPUT
	system(CLEAR);
	//Print title
	cout << title << endl;
	//Print GAME BOARD
	printf("   1   2   3\n");
	printf(" |---|---|---|\n");
	printf("1| %c | %c | %c |\n", board[0][0], board[0][1], board[0][2]);
	printf(" |---|---|---|\n");
	printf("2| %c | %c | %c |\n", board[1][0], board[1][1], board[1][2]);
        printf(" |---|---|---|\n");
        printf("3| %c | %c | %c |\n", board[2][0], board[2][1], board[2][2]);
        printf(" |---|---|---|\n");

	//DECIDE WHO'S TURN
	if((turn % 2) != 0){player = 'X';}else{player = 'O';}
	//RESET SELECTIONS
	column = row = 0;
	//INITIATE LOOP
	findPlace = true;
	//ANNOUNCE PLAYER SWITCH
	cout << "It's player '" << player << "'s turn!" << endl;
	do{
		//LOOP UNTIL PLAYER ENTERS 1, 2, OR 3.
		do{
			cout << "\nWHICH COLUMN?\n";
			getline(cin, buffer);
			//CATCH ANY ERRORS
			try{stringstream(buffer) >> column; if(column < 1 || column > 3){column=0;}} catch(...){column = 0;}
		}while(column == 0);
		//LOOP "  "   "    "    1, 2, OR 3.
		do{
			cout << "\nWHICH ROW?\n";
			getline(cin, buffer);
			//CATCH ANY ERRORS
        		try{stringstream(buffer) >> row; if(row < 1 || row > 3){row=0;}} catch(...){row = 0;}
		}while(row == 0);
	//CHECK IF SPOT IS EMPTY
	if(board[row-1][column-1] == ' ')
	{
		//PLACE PLAYER IF EMPTY, END LOOP
		board[row-1][column-1] = player; findPlace = false;
	}else{
		//REJECT PLACE, AND RE-RUN LOOP
		cout << "\nA player has already put their piece there!\n\n";
		row = 0; column = 0;
	}

	// IS THAT A WINNING MOVE ???
	if((checkBoard(board, player))){winner = player; inGame = false;}

	}while(findPlace);

	//PASS TO NEXT TURN
	turn++;
	//LOOP WHILE NO WINNER, AND NOT A DRAW
	}while(inGame && turn < 10);
	//CLEAR SCREEN
	system(CLEAR);
	//OUTPUT FINAL BOARD
        printf("   1   2   3\n");
        printf(" |---|---|---|\n");
        printf("1| %c | %c | %c |\n", board[0][0], board[0][1], board[0][2]);
        printf(" |---|---|---|\n");
        printf("2| %c | %c | %c |\n", board[1][0], board[1][1], board[1][2]);
        printf(" |---|---|---|\n");
        printf("3| %c | %c | %c |\n", board[2][0], board[2][1], board[2][2]);
        printf(" |---|---|---|\n");
	//ANNOUNCE WINNER
	if(winner != '-')
		cout << "\n\nThe game is over! Player '" << winner <<"' won!" << endl;
	else
		cout << "\n\nThe game is over! It ended in a draw!" << endl;
	//QUIT APPLICATION (TODO: ADD ENTER TO EXIT FOR WINDOWS)
	return 0;
}

bool checkBoard(char board[3][3], char player)
{
	//LEFT CORNER TO BOTTOM RIGHT
	if((board[0][0] == player) && (board[1][1] == player) && (board[2][2] == player))
		return true;
	//RIGHT CORNER TO BOTTOM LEFT
	else if((board[2][0] == player) && (board[1][1] == player) && (board[0][2] == player))
                return true;
	//FIRST COLUMN
        else if((board[0][0] == player) && (board[1][0] == player) && (board[2][0] == player))
                return true;
	//SECOND COLUMN
        else if((board[0][1] == player) && (board[1][1] == player) && (board[2][1] == player))
                return true;
	//THIRD COLUMN
        else if((board[0][2] == player) && (board[1][2] == player) && (board[2][2] == player))
                return true;
	//FIRST ROW
        else if((board[0][0] == player) && (board[0][1] == player) && (board[0][2] == player))
                return true;
	//SECOND COLUMN
        else if((board[1][0] == player) && (board[1][1] == player) && (board[1][2] == player))
                return true;
	//THIRD COLUMN
        else if((board[2][0] == player) && (board[2][1] == player) && (board[2][2] == player))
                return true;
        else
		return false;
}
